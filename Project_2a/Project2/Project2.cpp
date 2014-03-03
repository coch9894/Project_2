// Project2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Node.h"

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));

	int type = rand() % NON_TERMS;

	Node* test;

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
	
		//double t = test->Fitness(test);

		double t = test->eval(test, 5);

		//int t = test->size_of(test);

		cout << t << endl;

		cin >> temp;
	}
	return 0;
}

