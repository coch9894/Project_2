// Project2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Node.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int type = rand() % NON_TERMS;

	Node* test;

	char temp;

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

	test->Full(0,NULL, 10);

	cin >> temp;

	return 0;
}

