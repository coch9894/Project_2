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

Node * Node::copy( Node * t )
{
	Node * temp;
	switch(t->op_type)
	{
	case add:
		temp = new Add();
		break;
	case sub:
		temp = new Sub();
		break;
	case mul:
		temp = new Mul();
		break;
	case quo:
		temp = new Quo();
		break;
	case con:
		temp = new Con(t->val);
		break;
	case input:
		temp = new In();
		break;
	}

	temp->fitness = t->fitness;
	temp->op_type = t->op_type;
	temp->parent = t->parent;
	temp->size = t->size;
	temp->val = t->val;

	int count = 0;
	while( count < CHILDREN )
	{
		if( t->child[count] != NULL )
			temp->child[count] = temp->copy(t->child[count]);
		count++;
	}

	return temp;
}

Node * Node::get_node( int t )
{
	if( t == 0 )
		return this;
	if( child[0] != NULL )
		child[0]->get_node(t-1);
	else if( child[1] != NULL )
		child[1]->get_node(t-1);
	else
		return NULL;
}

double Node::Fitness( Node * t, double input[], double output[], int length )
{
	fitness = 0;
	for( int i = 0; i < length; i++ )
	{
		double z = t->eval(t,input[i]);
		fitness += ( z - output[i] ) * ( z - output[i] );
	}
	return sqrt(fitness);
}

void Node::Full( int depth, Node* p)
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
				child[count] = new Con(rand()%10);
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
				child[i] = new Con(rand()%10);
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

Add::Add(void)
{
	op_type = add;
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

Sub::Sub(void)
{
	op_type = sub;
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

Mul::Mul(void)
{
	op_type = mul;
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

Quo::Quo(void)
{
	op_type = quo;
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
	double temp = child[1]->eval(child[1], in);
	if( temp != 0 )
	{
		return child[0]->eval(child[0], in) / temp;
	}
	else
	{
		return 99999999;
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
	op_type = con;
	size = 1;
	val = x;
}

void Con::erase()
{
	delete this;
	return;
}

double Con::eval(Node* x, double in)
{
	return val;
}

In::In()
{
	int count = 0;
	while( count < CHILDREN )
	{
		child[count] = NULL;
		count++;
	}
	op_type = input;
	size = 1;
}

void In::erase()
{
	delete this;
	return;
}

double In::eval(Node* x, double in)
{
	return in;
}

// IF case for later

IF::IF(void)
{
	//op_type = iff;
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
