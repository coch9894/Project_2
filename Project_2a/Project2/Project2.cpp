// Project2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Population.h"

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));

	char temp = 'r';

	while( temp != 'q' )
	{
		Population* population = new Population();
		population->Evolve(100);
		cin >> temp;
	}
	return 0;
}

