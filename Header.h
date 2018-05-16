#include<iostream>

using namespace std;

typedef int BOOL;
#define TRUE 1
#define FALSE 0

typedef struct node
{
	int data;
	struct node * next;
}NODE, *PNODE, **PPNODE;

class Singly_Linear
{
private:
	PNODE head;
public:
	Singly_Linear();
	virtual BOOL InsertFirst(int);
	virtual BOOL InsertLast(int);
	virtual BOOL InsertAtPos(int, int);
	virtual BOOL DeleteFirst();
	virtual BOOL DeleteLast();
	virtual BOOL DeleteAtPos(int);
	virtual void Display();
	virtual int Count();
	~Singly_Linear();
};

class Singly_Circular
{
private:
	PNODE head;
	PNODE tail;
public:
	Singly_Circular();
	virtual BOOL InsertFirst(int);
	virtual BOOL InsertLast(int);
	virtual BOOL InsertAtPos(int,int);
	virtual BOOL DeleteFirst();
	virtual BOOL DeleteLast();
	virtual BOOL DeleteAtPos(int);
	virtual void Display();
	virtual int Count();
	~Singly_Circular();
};

typedef struct dnode
{
	struct dnode * prev;
	int data;
	struct dnode * next;
}DNODE, *DPNODE, **DPPNODE;

class Doubly_Linear
{
private:
	DPNODE head;
public:
	Doubly_Linear();
	~Doubly_Linear();
	virtual BOOL InsertFirst(int);
	virtual BOOL InsertLast(int);
	virtual BOOL InsertAtPos(int,int);
	virtual BOOL DeleteFirst();
	virtual BOOL DeleteLast();
	virtual BOOL DeleteAtPos(int);
	virtual void DisplayForward();
	virtual void DisplayBackward();
	virtual int Count();
};

class Doubly_Circular
{
private:
	DPNODE head;
	DPNODE tail;
public:
	Doubly_Circular();
	~Doubly_Circular();
	virtual BOOL InsertFirst(int);
	virtual BOOL InsertLast(int);
	virtual BOOL InsertAtPos(int, int);
	virtual BOOL DeleteFirst();
	virtual BOOL DeleteLast();
	virtual BOOL DeleteAtPos(int);
	virtual void DisplayForward();
	virtual void DisplayBackward();
	virtual int Count();
};

class Stack
{
private:
	DPNODE head;					//It holds the address of first node in stack
	DPNODE tail;					//It holds the address of last node in stack
public:
	Stack();
	virtual void Push(int);
	virtual int Pop();
	virtual void Display();
	virtual BOOL IsStackEmpty();
	~Stack();
};

class Queue
{
private:
	PNODE head;					//It holds the address of first node in queue
	PNODE tail;					//It holds the address of last node in queue
public:
	Queue();
	virtual void Enqueue(int);
	virtual int Dequeue();
	virtual void Display();
	virtual BOOL IsQueueEmpty();
	~Queue();
};
