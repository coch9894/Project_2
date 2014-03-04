// Project2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Node.h"

#define NUM_POINTS 5

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));

	int type = rand() % NON_TERMS;

	Node* test;

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
		switch(type)
		{
		case add:
			test = new Add();
			break;
		case sub:
			test = new Sub();
			break;
		case mul:
			test = new Mul();
			break;
		case quo:
			test = new Quo();
			break;
		}

		test->Full( 0, NULL);

		cout << test->Fitness(test, inputs, outputs, NUM_POINTS) << endl;

		cin >> temp;
	}
	return 0;
}

