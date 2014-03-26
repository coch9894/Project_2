#pragma once
//#include <queue>

typedef enum op
{
	add,
	sub,
	mul,
	quo,
	IF_,
	con,
	input
}op;

#define TERMS 2
#define NON_TERMS 5
#define MAX_DEPTH 3
#define CHILDREN 2

class Node
{
public:
	
	Node(void);
	
	virtual ~Node(void);

	double val;

	int size;

	double fitness;

	op op_type;
	
	Node* parent;
	
	Node* child[CHILDREN];

	int size_of( Node* );

	Node * copy( Node* );

	Node * get_node( int );

	void Full(int, Node*);

	double Fitness( Node*, double[], double[], int );

	virtual void erase(void) = 0;

	virtual double eval(Node*, double) = 0;
};


class Add : public Node
{
public:
	
	Add(void);

	void erase(void);

	double eval(Node*, double);
};

class Sub : public Node
{
public:

	Sub(void);

	void erase(void);

	double eval(Node*, double);
};

class Mul : public Node
{
public:

	Mul(void);

	void erase(void);

	double eval(Node*, double);
};

class Quo : public Node
{
public:

	Quo(void);

	void erase(void);

	double eval(Node*, double);
};

class Con : public Node
{
public:
	
	Con(double x);

	void erase(void);

	double eval(Node*, double);
};

class In : public Node
{
public:
	
	In(void);

	void erase(void);

	double eval(Node*, double);
};

class IF : public Node
{
public:
	
	IF(void);

	void erase(void);

	double eval(Node*, double);
};
