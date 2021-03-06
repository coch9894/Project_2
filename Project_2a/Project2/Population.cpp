#include "StdAfx.h"
#include "Population.h"

Population::Population(void)
{
	// Set the population up with random individuals

	int count = 0;
	while( count < POP_SIZE )
	{
		int type = rand() % NON_TERMS;

		switch(type)
		{
		case add:
			pop[count] = new Add();
			break;
		case sub:
			pop[count] = new Sub();
			break;
		case mul:
			pop[count] = new Mul();
			break;
		case quo:
			pop[count] = new Quo();
			break;
		case IF_:
			pop[count] = new IF();
			break;
		}

		pop[count]->Full(0,NULL);

		count++;
	}

	// Set up inputs and outputs as k -> k^2

	
	double x[NUM_POINTS] = { 52, 30.2, 23.2, 12, 0.6, -8, -20.8, -21.8, -27, -33.4, -41, -53.8,
	-52.8, -61, -55.4, -56, -63.8, -65.8, -60, -55.4, -57, -57.8, -49.8, -42, -42.4, -29,
	-28.8, -13.8, -13, -1.4, 15, -7.5, -5, 1.5, 1, 0.5, -7, 2.5, -1, 2.5, 1, -0.5, 5, 3.5,
	-1, 1.5, 7, -0.5, 2, -0.5, 10.20537863, 12.47229837, 12.60292251, 14.07559994, 12.28493299,
	19.68999988, 20.94679123, 19.99243556, 21.06059243, 22.6242444, 18.27989445, 14.6015212, 12.00004897,
	22.62273913, 20.31713541, 24.66839051, 28.10083518, 31.01892213, 27.95303678, 28.67447528, 35.2514392,
	31.03233741, 29.56048342, 34.44107329, 31.19301254, 35.12186997, 36.24506377, 31.28759691, 34.74938605, 44.02769935, 43.56472625 };

	for( int k = 0; k < NUM_POINTS; k++ )
	{
		input[k] = -40 + k;
		output[k] = x[k];
	}

	// Set avg_size

	calc_size();

	// Set avg_fitness

	calc_fitness();

}

Population::~Population(void)
{
	// erase the whole pop
	int count = 0;
	while( count < POP_SIZE )
	{
		pop[count]->erase();
	}
}

void Population::calc_fitness()
{
	// loop through summing then divide by total individuals
	avg_fitness = 0;
	best_fitness = 100000;
	for( int k = 0; k < POP_SIZE; k++ )
	{
		double temp = pop[k]->Fitness(pop[k],input,output,NUM_POINTS);
		if( temp < best_fitness )
		{
			best_fitness = temp;
			best_index = k;
		}
		avg_fitness += temp;
	}
	avg_fitness = avg_fitness / POP_SIZE;
}

void Population::calc_size()
{
	// loop through summing then divide by total individuals
	avg_size = 0;
	for( int k = 0; k < POP_SIZE; k++ )
	{
		avg_size += pop[k]->size_of(pop[k]);
	}
	avg_size = avg_size / POP_SIZE;
}

double Population::get_best_fitness()
{
	calc_fitness();
	return best_fitness;
}

double Population::get_avg_fitness()
{
	// re-calculate before returning
	calc_fitness();
	return avg_fitness;
}

double Population::get_avg_size()
{
	// re-calculate before returning
	calc_size();
	return avg_size;
}

void Population::print_avgs()
{
	// calculate then print
	calc_size();
	calc_fitness();

	cout << "These are the average values:" << endl;
	cout << "Average Size: " << avg_size << endl;
	cout << "Average Fitness: " << avg_fitness << endl;
	cout << "Best Fitness: " << best_fitness << endl;
}

void Population::print_avgs(int generation)
{
	// calculate then print
	calc_size();
	calc_fitness();

	cout << "These are the average values for generation:" << generation << endl;
	cout << "Average Size: " << avg_size << endl;
	cout << "Average Fitness: " << avg_fitness << endl;
	cout << "Best Fitness: " << best_fitness << endl << endl;
}

void Population::Evolve(int generations)
{
	int generation = 0;
	
	// filename
	ofstream o;
	o.open("numbers.txt");
	ofstream file;
	char sdate[9];
	char stime[9];
	_strdate_s(sdate);
	_strtime_s(stime);
	string filename = "results";
	filename.append(stime);
	filename.append("_");
	filename.append(sdate);
	filename.append(".txt");
	for(int i = 0; i < filename.length(); ++i)
	{
		if( filename[i] == '/' || filename[i] == ':')
		{
			filename[i] = '-';
		}
	}
	file.open(filename);

	while( generation <= generations )
	{
		if( generation % (generations / 10) == 0 )
		{
			print_avgs(generation);
		}

		if( FILE_PRINT )
		{
			file << avg_fitness << " " << best_fitness << endl;
			for( int i = 0; i < NUM_POINTS; i++ )
			{
				o << output[i] << " " << pop[best_index]->eval(pop[best_index],input[i]) << endl;
			}
			o.close();
		}

		calc_fitness();

		calc_size();

		Select();

		Crossover();

		Mutate();

		GenToPop();

		generation++;
	}
}

void Population::Select()
{
	for( int i = 0; i < POP_SIZE - ELITES; i++ )
	{
		for( int j = 0; j < N; j++ )
		{
			int random = (int)rand() % POP_SIZE;

			if( j == 0 )
			{
				switch(pop[random]->op_type)
				{
				case add:
					gen[i] = new Add();
					break;
				case sub:
					gen[i] = new Sub();
					break;
				case mul:
					gen[i] = new Mul();
					break;
				case quo:
					gen[i] = new Quo();
					break;
				}

				if( pop[random]->size < SIZE )
				{
					gen[i] = pop[random]->copy(pop[random]);
				}
				else
				{
					j--;
				}
			}
			else
			{

				if( pop[random]->fitness < gen[i]->fitness )
				{
					if( pop[random]->size < SIZE )
					{
						gen[i] = pop[random]->copy(pop[random]);
					}
					else
					{
						j--;
					}
				}

			}
		}
	}
}

void Population::Crossover()
{
	for( int i = 0; i < POP_SIZE - ELITES; i+=2 )
	{
		Node * s1; // source 1
		Node * s2; // source 2
		Node * node1; // switch 1
		Node * node2; // switch 2
		Node * p1; // parent 1
		Node * p2; // parent 2

		int rand1 = (int)rand() % gen[i]->size; // which node to trade
		int rand2 = (int)rand() % gen[i+1]->size; // which node to trade

		s1 = gen[i]->get_node(rand1); // what we swap
		
		s2 = gen[i+1]->get_node(rand2); // what we swap

		p1 = s1->parent; // parent
		p2 = s2->parent; // parent

		node1 = gen[i]->copy(s1); // new memory
		node2 = gen[i+1]->copy(s2); // new memory

		s1->erase(); // remove the old
		s2->erase(); // remove the old
		s1 = NULL; // make the pointer null
		s2 = NULL; // make the pointer null

		int k = 0;
		if( p1 != NULL )
		{
			while( p1->child[k] != NULL )
			{
				k++;
			}
			if( p1->child[k] == NULL )
			{
				p1->child[k] = node2;
				node2->parent = p1;
			}
			else
			{
				cout << "DANGER, THERE BE GHOSTS!" << endl;
				cin >> k;
				exit(-1);
			}
		}
		else
		{
			gen[i] = node2;
			node2->parent = NULL;
		}

		int j = 0;
		if( p2 != NULL )
		{
			while( p2->child[j] != NULL )
			{
				j++;
			}
			if( p2->child[j] == NULL )
			{
				p2->child[j] = node1;
				node1->parent = p2;
			}
			else
			{
				cout << "DANGER, THERE BE GHOSTS!" << endl;
				cin  >> j;
				exit(-1);
			}
		}
		else
		{
			gen[i+1] = node1;
			node1->parent = NULL;
		}
	}
}

void Population::Mutate()
{
	for( int i = 0; i < POP_SIZE - ELITES; i++ )
	{
		double prob = rand();
		if( prob < .1 )
		{
			int value = rand() % gen[i]->size;
			Node * swap = gen[i]->get_node(value);
			Node * p = swap->parent;
			Node * n;

			int type = rand() % NON_TERMS;
			
			switch(type)
			{
			case add:
				n = new Add();
				break;
			case sub:
				n = new Sub();
				break;
			case mul:
				n = new Mul();
				break;
			case quo:
				n = new Quo();
				break;
			case IF_:
				n = new IF();
				break;
			}

			int count = 0;
			while( count  < CHILDREN )
			{
				n->child[count] = swap->copy(swap->child[count]);
			}
			swap->erase();
			swap = NULL;

			int k = 0;
			if( p != NULL )
			{
				while( p->child[k] != NULL )
				{
					k++;
				}
				if( p->child[k] == NULL )
				{
					p->child[k] = n;
					n->parent = p;
				}
				else
				{
					cout << "DANGER, THERE BE GHOSTS!" << endl;
					cin >> k;
					exit(-1);
				}
			}
			else
			{
				gen[i] = n;
				n->parent = NULL;
			}
		}
	}
}

void Population::GenToPop()
{
	pop[POP_SIZE-1] = pop[best_index]->copy(pop[best_index]);

	int i = 0;
	for( i = 0; i < POP_SIZE - ELITES; i++ )
	{
		pop[i] = gen[i]->copy(gen[i]);
	}
	while( i < POP_SIZE )
	{
		pop[i] = pop[POP_SIZE-1]->copy(pop[POP_SIZE-1]);
		i++;
	}

	calc_size();
	calc_fitness();
	//print_avgs();
}