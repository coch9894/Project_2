#pragma once

#include "Node.h"

#define POP_SIZE 1000

class Population
{
public:

	Population(void);

	~Population(void);

	Node * pop[POP_SIZE];
};

