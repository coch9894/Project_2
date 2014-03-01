#pragma once

typedef enum op
{
	add,
	sub,
	mul,
	quo,
	con,
	input
}op;

#define TERMS 2
#define NON_TERMS 4
#define OPS 6
#define MAX_DEPTH 5
#define CHILDREN 2

class Node
{
public:
	
	Node(void);
	
	virtual ~Node(void);
	
	Node* parent;
	
	Node* child[CHILDREN];

	void Full(int, Node*);
};


class Add : public Node
{
public:
	
	Add(void);

	double eval(double);
};

class Sub : public Node
{
public:

	Sub(void);

	double eval(double);
};

class Mul : public Node
{
public:

	Mul(void);

	double eval(double);
};

class Quo : public Node
{
public:

	Quo(void);

	double eval(double);
};

class Con : public Node
{
public:
	
	Con(void);

	double eval(double);
		
	double val;
};

class In : public Node
{
public:
	
	In(void);

	double eval(double);
		
	double val;
};

class IF : public Node
{
public:
	
	IF(void);

	double eval(double);

	bool test;
};
