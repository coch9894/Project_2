#include "StdAfx.h"
#include "Node.h"


Node::Node(void)
{
	Full(0,NULL);
}

Node::~Node(void)
{
}

void Node::Full(int depth, Node* p)
{
	parent = p;

	// if the head create yourself
	if( depth == 0 )
	{
		int type = NON_TERMS + rand() % TERMS;
		
		switch(type)
		{
		case add:
			parent = new Add();
			break;
		case sub:
			parent = new Sub();
			break;
		case mul:
			parent = new Mul();
			break;
		case quo:
			parent = new Quo();
			break;
		case con:
			parent = new Con();
			break;
		case input:
			parent = new In();
			break;
		}
	}
	
	if( depth < MAX_DEPTH )
	{
		int count = 0;
		while( count < CHILDREN )
		{
			int type = NON_TERMS + rand() % TERMS;
			
			switch(type)
			{
			case add:
				child[count] = new Add();
				Full(depth+1, child[count]);
				break;
			case sub:
				child[count] = new Sub();
				Full(depth+1, child[count]);
				break;
			case mul:
				child[count] = new Mul();
				Full(depth+1, child[count]);
				break;
			case quo:
				child[count] = new Quo();
				Full(depth+1, child[count]);
				break;
			case con:
				child[count] = new Con();
				Full(depth+1, child[count]);
				break;
			case input:
				child[count] = new In();
				Full(depth+1, child[count]);
				break;
			}

			count++;
		}
	}
}

Add::Add(void)
{
}

double Add::eval(double x)
{
	return x;
}

Sub::Sub(void)
{
}

double Sub::eval(double x)
{
	return x;
}

Mul::Mul(void)
{
}

double Mul::eval(double x)
{
	return x;
}

Quo::Quo(void)
{
}

double Quo::eval(double x)
{
	return x;
}

Con::Con(void)
{
}

double Con::eval(double x)
{
	return x;
}

In::In(void)
{
}

double In::eval(double x)
{
	return x;
}

IF::IF(void)
{
}

double IF::eval(double x)
{
	return x;
}
