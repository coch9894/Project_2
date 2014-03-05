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
		}

		pop[count]->Full(0,NULL);

		count++;
	}

	// Set up inputs and outputs as k -> k^2

	for( int k = 0; k < NUM_POINTS; k++ )
	{
		input[k] = (k+1);
		output[k] = (k+1) * (k+1);
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