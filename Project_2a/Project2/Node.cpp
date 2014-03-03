#include "StdAfx.h"
#include "Node.h"


Node::Node(void)
{
}

Node::~Node(void)
{
}

Add::Add(void)
{
}

void Add::erase()
{
	int count = 0;
	while( count < CHILDREN )
	{
		child[count]->erase();
	}
	delete this;
}

double Add::eval(Node* x)
{
	return child[0]->eval(child[0]) + child[1]->eval(child[1]);
}

void Add::Full( int depth, Node* p, double in )
{
	parent = p;

	val = in;

	// if the head create yourself
	if( depth == 0 )
	{
		parent = new Add();
	}

	if( depth < MAX_DEPTH )
	{
		int count = 0;
		while( count < CHILDREN )
		{
			int type = rand() % NON_TERMS;
			
			switch(type)
			{
			case add:
				child[count] = new Add();
				child[count]->Full(depth+1, child[count], in);
				break;
			case sub:
				child[count] = new Sub();
				child[count]->Full(depth+1, child[count], in);
				break;
			case mul:
				child[count] = new Mul();
				child[count]->Full(depth+1, child[count], in);
				break;
			case quo:
				child[count] = new Quo();
				child[count]->Full(depth+1, child[count], in);
				break;
			case con:
				child[count] = new Con(rand()%100);
				break;
			case input:
				child[count] = new In(in);
				break;
			}

			count++;
		}
	}

	else
	{
		int type = (rand() % TERMS) + NON_TERMS;
		int i = 0;
		while( i < CHILDREN )
		{
			switch(type)
			{
			case con:
				child[i] = new Con(rand()%100);
				break;
			case input:
				child[i] = new In(in);
				break;
			}
			i++;
		}
	}
}

Sub::Sub(void)
{
}

void Sub::erase()
{
	int count = 0;
	while( count < CHILDREN )
	{
		child[count]->erase();
	}
	delete this;
}

double Sub::eval(Node* x)
{
	return child[0]->eval(child[0]) - child[1]->eval(child[1]);
}

void Sub::Full( int depth, Node* p, double in )
{
	parent = p;

	val = in;

	// if the head create yourself
	if( depth == 0 )
	{
		parent = new Sub();
	}

	if( depth < MAX_DEPTH )
	{
		int count = 0;
		while( count < CHILDREN )
		{
			int type = rand() % NON_TERMS;
			
			switch(type)
			{
			case add:
				child[count] = new Add();
				child[count]->Full(depth+1, child[count], in);
				break;
			case sub:
				child[count] = new Sub();
				child[count]->Full(depth+1, child[count], in);
				break;
			case mul:
				child[count] = new Mul();
				child[count]->Full(depth+1, child[count], in);
				break;
			case quo:
				child[count] = new Quo();
				child[count]->Full(depth+1, child[count], in);
				break;
			case con:
				child[count] = new Con(rand()%100);
				break;
			case input:
				child[count] = new In(in);
				break;
			}

			count++;
		}
	}

	else
	{
		int type = (rand() % TERMS) + NON_TERMS;
		int i = 0;
		while( i < CHILDREN )
		{
			switch(type)
			{
			case con:
				child[i] = new Con(rand()%100);
				break;
			case input:
				child[i] = new In(in);
				break;
			}
			i++;
		}
	}
}

Mul::Mul(void)
{
}

void Mul::erase()
{
	int count = 0;
	while( count < CHILDREN )
	{
		child[count]->erase();
	}
	delete this;
}

double Mul::eval(Node* x)
{
	return child[0]->eval(child[0]) * child[1]->eval(child[1]);
}

void Mul::Full( int depth, Node* p, double in )
{
	parent = p;

	val = in;

	// if the head create yourself
	if( depth == 0 )
	{
		parent = new Mul();
	}

	if( depth < MAX_DEPTH )
	{
		int count = 0;
		while( count < CHILDREN )
		{
			int type = rand() % NON_TERMS;
			
			switch(type)
			{
			case add:
				child[count] = new Add();
				child[count]->Full(depth+1, child[count], in);
				break;
			case sub:
				child[count] = new Sub();
				child[count]->Full(depth+1, child[count], in);
				break;
			case mul:
				child[count] = new Mul();
				child[count]->Full(depth+1, child[count], in);
				break;
			case quo:
				child[count] = new Quo();
				child[count]->Full(depth+1, child[count], in);
				break;
			case con:
				child[count] = new Con(rand()%100);
				break;
			case input:
				child[count] = new In(in);
				break;
			}

			count++;
		}
	}

	else
	{
		int type = (rand() % TERMS) + NON_TERMS;
		int i = 0;
		while( i < CHILDREN )
		{
			switch(type)
			{
			case con:
				child[i] = new Con(rand()%100);
				break;
			case input:
				child[i] = new In(in);
				break;
			}
			i++;
		}
	}
}

Quo::Quo(void)
{
}

void Quo::erase()
{
	int count = 0;
	while( count < CHILDREN )
	{
		child[count]->erase();
	}
	delete this;
}

double Quo::eval(Node* x)
{
	return child[0]->eval(child[0]) / child[1]->eval(child[1]);
}

void Quo::Full( int depth, Node* p, double in )
{
	parent = p;

	val = in;

	// if the head create yourself
	if( depth == 0 )
	{
		parent = new Quo();
	}

	if( depth < MAX_DEPTH )
	{
		int count = 0;
		while( count < CHILDREN )
		{
			int type = rand() % NON_TERMS;
			
			switch(type)
			{
			case add:
				child[count] = new Add();
				child[count]->Full(depth+1, child[count], in);
				break;
			case sub:
				child[count] = new Sub();
				child[count]->Full(depth+1, child[count], in);
				break;
			case mul:
				child[count] = new Mul();
				child[count]->Full(depth+1, child[count], in);
				break;
			case quo:
				child[count] = new Quo();
				child[count]->Full(depth+1, child[count], in);
				break;
			case con:
				child[count] = new Con(rand()%100);
				break;
			case input:
				child[count] = new In(in);
				break;
			}

			count++;
		}
	}

	else
	{
		int type = (rand() % TERMS) + NON_TERMS;
		int i = 0;
		while( i < CHILDREN )
		{
			switch(type)
			{
			case con:
				child[i] = new Con(rand()%100);
				break;
			case input:
				child[i] = new In(in);
				break;
			}
			i++;
		}
	}
}

Con::Con(double x)
{
	val = x;
}

void Con::erase()
{
	int count = 0;
	while( count < CHILDREN )
	{
		child[count]->erase();
	}
	delete this;
}

double Con::eval(Node* x)
{
	return val;
}

void Con::Full( int depth, Node* p, double in )
{
	parent = p;

	// if the head create yourself
	if( depth == 0 )
	{
		exit(-1);
	}

	if( depth < MAX_DEPTH )
	{
		exit(-1);
	}

	else
	{
		/*
		int type = (rand() % TERMS) + NON_TERMS;
		int i = 0;
		while( i < CHILDREN )
		{
			switch(type)
			{
			case con:
				child[i] = new Con(rand()%100);
				break;
			case input:
				child[i] = new In(rand()%100);
				break;
			}
			i++;
		}
		*/
		exit(-1);
	}
}

In::In(double x)
{
	val = x;
}

void In::erase()
{
	int count = 0;
	while( count < CHILDREN )
	{
		child[count]->erase();
	}
	delete this;
}

double In::eval(Node* x)
{
	return val;
}

void In::Full( int depth, Node* p, double in )
{
	parent = p;

	// if the head create yourself
	if( depth == 0 )
	{
		exit(-1);
	}

	if( depth < MAX_DEPTH )
	{
		exit(-1);
	}

	else
	{
		/*
		int type = (rand() % TERMS) + NON_TERMS;
		int i = 0;
		while( i < CHILDREN )
		{
			switch(type)
			{
			case con:
				child[i] = new Con(rand()%100);
				break;
			case input:
				child[i] = new In(rand()%100);
				break;
			}
			i++;
		}
		*/
		exit(-1);
	}
}


// IF case for later

IF::IF(void)
{
}

void IF::erase()
{
	int count = 0;
	while( count < CHILDREN )
	{
		child[count]->erase();
	}
	delete this;
}

double IF::eval(Node* x)
{
	return 0;
}

void IF::Full( int depth, Node* p, double in )
{
	parent = p;

	val = in;

	// if the head create yourself
	if( depth == 0 )
	{
		parent = new IF();
	}

	if( depth < MAX_DEPTH )
	{
		int count = 0;
		while( count < CHILDREN )
		{
			int type = rand() % NON_TERMS;
			
			switch(type)
			{
			case add:
				child[count] = new Add();
				child[count]->Full(depth+1, child[count], in);
				break;
			case sub:
				child[count] = new Sub();
				child[count]->Full(depth+1, child[count], in);
				break;
			case mul:
				child[count] = new Mul();
				child[count]->Full(depth+1, child[count], in);
				break;
			case quo:
				child[count] = new Quo();
				child[count]->Full(depth+1, child[count], in);
				break;
			case con:
				child[count] = new Con(rand()%100);
				break;
			case input:
				child[count] = new In(in);
				break;
			}

			count++;
		}
	}

	else
	{
		int type = (rand() % TERMS) + NON_TERMS;
		int i = 0;
		while( i < CHILDREN )
		{
			switch(type)
			{
			case con:
				child[i] = new Con(rand()%100);
				break;
			case input:
				child[i] = new In(in);
				break;
			}
			i++;
		}
	}
}
