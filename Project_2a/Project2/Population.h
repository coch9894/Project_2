#pragma once

#include "Node.h"

#define POP_SIZE 1000
#define NUM_POINTS 5

class Population
{
public:

	Population(void);

	~Population(void);

	void print_avgs();

	double get_best_fitness();

	double get_avg_fitness();

	double get_avg_size();

private:

	Node * pop[POP_SIZE];

	double best_fitness;

	double avg_fitness;

	double avg_size;

	double input[NUM_POINTS];

	double output[NUM_POINTS];

	void calc_size();

	void calc_fitness();
};

