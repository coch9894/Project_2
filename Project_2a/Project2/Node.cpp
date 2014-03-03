#include "StdAfx.h"
#include "Node.h"


Node::Node(void)
{
}

Node::~Node(void)
{
}

int Node::size_of( Node * t )
{
	int count = 0;
	int temp = 1;
	while( count < CHILDREN )
	{
		if( t->child[count] != NULL )
		{
			temp += size_of( t->child[count] );
		}
		else //( t->child[count] == NULL )
		{
			temp = 1;
		}
		count++;
	}
	size = temp;
	return temp;
}

double Node::Fitness( Node * t, double expected )
{
	return t->eval(t, 5);
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
		count++;
	}
	delete this;
}

double Add::eval(Node* x, double in)
{
	return child[0]->eval(child[0], in) + child[1]->eval(child[1], in);
}

void Add::Full( int depth, Node* p)
{
	//cout << "Add " << endl;

	parent = p;

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
				child[count]->Full(depth+1, child[count]);
				break;
			case sub:
				child[count] = new Sub();
				child[count]->Full(depth+1, child[count]);
				break;
			case mul:
				child[count] = new Mul();
				child[count]->Full(depth+1, child[count]);
				break;
			case quo:
				child[count] = new Quo();
				child[count]->Full(depth+1, child[count]);
				break;
			case con:
				child[count] = new Con(rand()%100);
				child[count]->parent = this;
				break;
			case input:
				child[count] = new In();
				child[count]->parent = this;
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
				child[i]->parent = this;
				break;
			case input:
				child[i] = new In();
				child[i]->parent = this;
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
		count++;
	}
	delete this;
}

double Sub::eval(Node* x, double in)
{
	return child[0]->eval(child[0], in) - child[1]->eval(child[1], in);
}

void Sub::Full( int depth, Node* p )
{
	//cout << "Sub " << endl;

	parent = p;

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
				child[count]->Full(depth+1, child[count]);
				break;
			case sub:
				child[count] = new Sub();
				child[count]->Full(depth+1, child[count]);
				break;
			case mul:
				child[count] = new Mul();
				child[count]->Full(depth+1, child[count]);
				break;
			case quo:
				child[count] = new Quo();
				child[count]->Full(depth+1, child[count]);
				break;
			case con:
				child[count] = new Con(rand()%100);
				child[count]->parent = this;
				break;
			case input:
				child[count] = new In();
				child[count]->parent = this;
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
				child[i]->parent = this;
				break;
			case input:
				child[i] = new In();
				child[i]->parent = this;
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
		count++;
	}
	delete this;
}

double Mul::eval(Node* x, double in )
{
	return child[0]->eval(child[0], in) * child[1]->eval(child[1], in);
}

void Mul::Full( int depth, Node* p )
{
	//cout << "Mul " << endl;

	parent = p;

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
				child[count]->Full(depth+1, child[count]);
				break;
			case sub:
				child[count] = new Sub();
				child[count]->Full(depth+1, child[count]);
				break;
			case mul:
				child[count] = new Mul();
				child[count]->Full(depth+1, child[count]);
				break;
			case quo:
				child[count] = new Quo();
				child[count]->Full(depth+1, child[count]);
				break;
			case con:
				child[count] = new Con(rand()%100);
				child[count]->parent = this;
				break;
			case input:
				child[count] = new In();
				child[count]->parent = this;
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
				child[i]->parent = this;
				break;
			case input:
				child[i] = new In();
				child[i]->parent = this;
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
		count++;
	}
	delete this;
}

double Quo::eval(Node* x, double in)
{
	return child[0]->eval(child[0], in) / child[1]->eval(child[1], in);
}

void Quo::Full( int depth, Node* p)
{
	//cout << "Quo" << endl;

	parent = p;

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
				child[count]->Full(depth+1, child[count]);
				break;
			case sub:
				child[count] = new Sub();
				child[count]->Full(depth+1, child[count]);
				break;
			case mul:
				child[count] = new Mul();
				child[count]->Full(depth+1, child[count]);
				break;
			case quo:
				child[count] = new Quo();
				child[count]->Full(depth+1, child[count]);
				break;
			case con:
				child[count] = new Con(rand()%100);
				child[count]->parent = this;
				break;
			case input:
				child[count] = new In();
				child[count]->parent = this;
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
				child[i]->parent = this;
				break;
			case input:
				child[i] = new In();
				child[i]->parent = this;
				break;
			}
			i++;
		}
	}
}

Con::Con(double x)
{
	int count = 0;
	while( count < CHILDREN )
	{
		child[count] = NULL;
		count++;
	}
	size = 1;
	val = x;
}

void Con::erase()
{
	int count = 0;
	while( count < CHILDREN )
	{
		child[count]->erase();
		count++;
	}
	delete this;
}

double Con::eval(Node* x, double in)
{
	return val;
}

void Con::Full( int depth, Node* p )
{
	exit( -1 );
}

In::In()
{
	int count = 0;
	while( count < CHILDREN )
	{
		child[count] = NULL;
		count++;
	}
	size = 1;
}

void In::erase()
{
	int count = 0;
	while( count < CHILDREN )
	{
		child[count]->erase();
		count++;
	}
	delete this;
}

double In::eval(Node* x, double in)
{
	return in;
}

void In::Full( int depth, Node* p )
{
	exit( -1 );
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
		count++;
	}
	delete this;
}

double IF::eval(Node* x, double in)
{
	return 0;
}

void IF::Full( int depth, Node* p )
{
	parent = p;

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
				child[count]->Full(depth+1, child[count]);
				break;
			case sub:
				child[count] = new Sub();
				child[count]->Full(depth+1, child[count]);
				break;
			case mul:
				child[count] = new Mul();
				child[count]->Full(depth+1, child[count]);
				break;
			case quo:
				child[count] = new Quo();
				child[count]->Full(depth+1, child[count]);
				break;
			case con:
				child[count] = new Con(rand()%100);
				child[count]->parent = this;
				break;
			case input:
				child[count] = new In();
				child[count]->parent = this;
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
				child[i]->parent = this;
				break;
			case input:
				child[i] = new In();
				child[i]->parent = this;
				break;
			}
			i++;
		}
	}
}
