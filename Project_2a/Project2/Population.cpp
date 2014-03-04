#include "StdAfx.h"
#include "Population.h"


Population::Population(void)
{
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

}


Population::~Population(void)
{
}
