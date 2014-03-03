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
	
	Node* parent;
	
	Node* child[CHILDREN];

	int size_of( Node* );

	virtual void erase(void) = 0;

	virtual void Full(int, Node*, double) = 0;

	virtual double eval(Node*) = 0;
};


class Add : public Node
{
public:
	
	Add(void);

	void erase(void);

	double eval(Node*);

	void Full(int, Node*, double);
};

class Sub : public Node
{
public:

	Sub(void);

	void erase(void);

	double eval(Node*);

	void Full(int, Node*, double);
};

class Mul : public Node
{
public:

	Mul(void);

	void erase(void);

	double eval(Node*);

	void Full(int, Node*, double);
};

class Quo : public Node
{
public:

	Quo(void);

	void erase(void);

	double eval(Node*);

	void Full(int, Node*, double);
};

class Con : public Node
{
public:
	
	Con(double x);

	void erase(void);

	double eval(Node*);

	void Full(int, Node*, double);
};

class In : public Node
{
public:
	
	In(double x);

	void erase(void);

	double eval(Node*);

	void Full(int, Node*, double);
};

class IF : public Node
{
public:
	
	IF(void);

	void erase(void);

	double eval(Node*);

	void Full(int, Node*, double);

	bool test;
};
