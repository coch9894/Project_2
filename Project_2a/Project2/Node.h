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

	double val;

	int size;

	int avg_size;

	double fitness;

	double avg_fitness;
	
	Node* parent;
	
	Node* child[CHILDREN];

	int size_of( Node* );

	double Fitness( Node*, double[], double[], int );

	virtual void erase(void) = 0;

	virtual void Full(int, Node*) = 0;

	virtual double eval(Node*, double) = 0;
};


class Add : public Node
{
public:
	
	Add(void);

	void erase(void);

	double eval(Node*, double);

	void Full(int, Node*);
};

class Sub : public Node
{
public:

	Sub(void);

	void erase(void);

	double eval(Node*, double);

	void Full(int, Node*);
};

class Mul : public Node
{
public:

	Mul(void);

	void erase(void);

	double eval(Node*, double);

	void Full(int, Node*);
};

class Quo : public Node
{
public:

	Quo(void);

	void erase(void);

	double eval(Node*, double);

	void Full(int, Node*);
};

class Con : public Node
{
public:
	
	Con(double x);

	void erase(void);

	double eval(Node*, double);

	void Full(int, Node*);
};

class In : public Node
{
public:
	
	In(void);

	void erase(void);

	double eval(Node*, double);

	void Full(int, Node*);
};

class IF : public Node
{
public:
	
	IF(void);

	void erase(void);

	double eval(Node*, double);

	void Full(int, Node*);

	bool test;
};
