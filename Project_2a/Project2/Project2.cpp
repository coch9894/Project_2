// Project2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Node.h"

#include "Population.h"

#define NUM_POINTS 5

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));

	double inputs[NUM_POINTS];
	double outputs[NUM_POINTS];

	int i = 0;
	while( i < NUM_POINTS )
	{
		inputs[i] = i+1;
		outputs[i] = (i+1) * (i+1);
		i++;
	}

	char temp = 'r';

	while( temp != 'q' )
	{
		Population* population = new Population();
		cout << population->pop[0]->Fitness(population->pop[0],inputs,outputs,NUM_POINTS) << endl;
		cin >> temp;
	}
	return 0;
}

