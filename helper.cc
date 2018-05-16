#include"Header.h"

Singly_Linear::Singly_Linear()
{
	head = NULL;
}

BOOL Singly_Linear::InsertFirst(int iNo)
{
	PNODE newn = NULL;
	newn = new NODE;

	if (newn == NULL)
	{
		return FALSE;
	}
	newn->data = iNo;
	newn->next = NULL;

	if (head == NULL)
	{
		head = newn;
		return TRUE;
	}
	else
	{
		newn->next = head;
		head = newn;
		return TRUE;
	}
}

BOOL Singly_Linear::InsertLast(int iNo)
{
	PNODE temp = head;
	PNODE newn = NULL;
	newn = new NODE;

	if (newn == NULL)
	{
		return FALSE;
	}
	newn->data = iNo;
	newn->next = NULL;

	if (head == NULL)
	{
		head = newn;
		return TRUE;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
		return TRUE;
	}
}

BOOL Singly_Linear::InsertAtPos(int iNo, int iPos)
{
	PNODE temp = head;
	PNODE newn = NULL;

	if ((iPos < 1) || (iPos > (Count() + 1)))
	{
		return FALSE;
	}
	if (iPos == 1)
	{
		return(InsertFirst(iNo));
	}
	if (iPos == (Count() + 1))
	{
		return(InsertLast(iNo));
	}

	newn = new NODE;
	newn->data = iNo;
	newn->next = NULL;

	while (iPos > 2)
	{
		temp = temp->next;
		iPos--;
	}
	newn->next = temp->next;
	temp->next = newn;

	return TRUE;
}

BOOL Singly_Linear::DeleteFirst()
{
	PNODE temp = head;

	if ((head == NULL))
	{
		return FALSE;
	}
	else
	{
		head = head->next;
		delete temp;
		return TRUE;
	}
}

BOOL Singly_Linear::DeleteLast()
{
	PNODE temp = head;

	if (head == NULL)
	{
		return FALSE;
	}
	else if(head->next == NULL)
	{
		delete head;
		head = NULL;
	}
	else
	{
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		delete (temp->next);
		temp->next = NULL;
	}
}

BOOL Singly_Linear::DeleteAtPos(int iPos)
{
	PNODE temp = head;
	PNODE temp1 = NULL;

	if ((iPos < 1) || (iPos > Count()))
	{
		return FALSE;
	}
	if (iPos == 1)
	{
		return(DeleteFirst());
	}
	if (iPos == Count())
	{
		return(DeleteLast());
	}

	while (iPos > 2)
	{
		temp = temp->next;
	}
	temp1 = temp->next;
	temp->next = temp->next->next;
	delete temp1;

	return TRUE;
}

void Singly_Linear::Display()
{
	PNODE temp = head;

	if (head == NULL)
	{
		cout << "Linked List empty\n";
		return;
	}

	while (temp != NULL)
	{
		cout << temp->data << "\t";
		temp = temp->next;
	}
	cout << "\n";
}

int Singly_Linear::Count()
{
	PNODE temp = head;
	int iCnt = 0;

	if (head == NULL)
	{
		cout << "Linked List empty\n";
		return iCnt;
	}

	while (temp != NULL)
	{
		iCnt++;
		temp = temp->next;
	}
	return iCnt;
}

Singly_Linear::~Singly_Linear()
{
	PNODE temp = head;

	while (temp != NULL)
	{
		temp = temp->next;
		delete head;
		head = temp;
	}
}

extern "C"
{
	Singly_Linear* createSingly_Linear()
	{
		return new Singly_Linear;
	}

	void destroySingly_Linear(Singly_Linear *p)
	{
		delete p;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////

Singly_Circular::Singly_Circular()
{
	head = NULL;
	tail = NULL;
}

BOOL Singly_Circular::InsertFirst(int iNo)
{
	PNODE newn = NULL;
	newn = new NODE;

	if (newn == NULL)
	{
		return FALSE;
	}
	newn->data = iNo;
	newn->next = NULL;

	if ((head == NULL) && (tail == NULL))
	{
		head = tail = newn;
		tail->next = head;
		return TRUE;
	}
	else
	{
		newn->next = head;
		head = newn;
		tail->next = head;
		return TRUE;
	}
}

BOOL Singly_Circular::InsertLast(int iNo)
{
	PNODE newn = NULL;
	newn = new NODE;

	if (newn == NULL)
	{
		return FALSE;
	}
	newn->data = iNo;
	newn->next = NULL;

	if ((head == NULL) && (tail == NULL))
	{
		head = tail = newn;
		tail->next = head;
		return TRUE;
	}
	else
	{
		tail->next = newn;
		tail = newn;
		tail->next = head;
		return TRUE;
	}
}

BOOL Singly_Circular::InsertAtPos(int iNo, int iPos)
{
	PNODE temp = head;

	if ((iPos < 1) || (iPos > (Count() + 1)))
	{
		return FALSE;
	}
	if (iPos == 1)
	{
		return(InsertFirst(iNo));
	}
	if (iPos == (Count() + 1))
	{
		return(InsertLast(iNo));
	}

	PNODE newn = NULL;
	newn = new NODE;

	if (newn == NULL)
	{
		return FALSE;
	}
	newn->data = iNo;
	newn->next = NULL;

	while (iPos > 2)
	{
		temp = temp->next;
		iPos--;
	}
	newn->next = temp->next;
	temp->next = newn;
	return TRUE;
}

BOOL Singly_Circular::DeleteFirst()
{
	if ((head == NULL) && (tail == NULL))
	{
		return FALSE;
	}
	else if(head == tail)
	{
		delete head;
		head = tail = NULL;
		return TRUE;
	}
	else
	{
		head = head->next;
		delete (tail->next);
		tail->next = head;
		return TRUE;
	}
}

BOOL Singly_Circular::DeleteLast()
{
	PNODE temp = head;

	if ((head == NULL) && (tail == NULL))
	{
		return FALSE;
	}
	else if(head == tail)
	{
		delete tail;
		head = tail = NULL;
		return TRUE;
	}
	else
	{
		while (temp->next != tail)
		{
			temp = temp->next;
		}
		delete tail;
		tail = temp;
		tail->next = head;
		return TRUE;
	}
}

BOOL Singly_Circular::DeleteAtPos(int iPos)
{
	PNODE temp = head;

	if ((iPos < 1) || (iPos > Count()))
	{
		return FALSE;
	}
	if (iPos == 1)
	{
		return(DeleteFirst());
	}
	if (iPos == Count())
	{
		return(DeleteLast());
	}

	while (iPos > 2)
	{
		temp = temp->next;
		iPos--;
	}
	PNODE temp1 = temp->next;
	temp->next = temp->next->next;
	delete temp1;
	return TRUE;
}

void Singly_Circular::Display()
{
	PNODE temp = head;

	if ((head == NULL) && (tail == NULL))
	{
		return;
	}

	do
	{
		cout << temp->data << "\t";
		temp = temp->next;
	} while (temp != tail->next);
	cout << "\n";
}

int Singly_Circular::Count()
{
	PNODE temp = head;
	int iCnt = 0;

	if ((head == NULL) && (tail == NULL))
	{
		return iCnt;
	}

	do
	{
		iCnt++;
		temp = temp->next;
	} while (temp != tail->next);
	return iCnt;
}

Singly_Circular::~Singly_Circular()
{

}

extern "C"
{
	Singly_Circular* createSingly_Circular()
	{
		return new Singly_Circular;
	}

	void destroySingly_Circular(Singly_Circular *p)
	{
		delete p;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////

Doubly_Linear::Doubly_Linear()
{
	head = NULL;
}

BOOL Doubly_Linear::InsertFirst(int iNo)
{
	DPNODE newn = NULL;
	newn = new DNODE;

	if (newn == NULL)
	{
		return FALSE;
	}
	newn->data = iNo;
	newn->next = NULL;
	newn->prev = NULL;

	if (head == NULL)
	{
		head = newn;
		return TRUE;
	}
	else
	{
		newn->next = head;
		head->prev = newn;
		head = newn;
		return TRUE;
	}
}

BOOL Doubly_Linear::InsertLast(int iNo)
{
	DPNODE temp = head;
	DPNODE newn = NULL;
	newn = new DNODE;

	if (newn == NULL)
	{
		return FALSE;
	}
	newn->data = iNo;
	newn->next = NULL;
	newn->prev = NULL;

	if (head == NULL)
	{
		head = newn;
		return TRUE;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
		newn->prev = temp;
		return TRUE;
	}
}

BOOL Doubly_Linear::InsertAtPos(int iNo, int iPos)
{
	DPNODE temp = head;

	if ((iPos < 1) || (iPos > (Count() + 1)))
	{
		return FALSE;
	}
	if (iPos == 1)
	{
		return(InsertFirst(iNo));
	}
	if(iPos == Count() + 1)
	{
		return(InsertLast(iNo));
	}

	DPNODE newn = new DNODE;

	if (newn == NULL)
	{
		return FALSE;
	}
	newn->data = iNo;
	newn->next = NULL;
	newn->prev = NULL;

	while (iPos > 2)
	{
		temp = temp->next;
		iPos--;
	}
	newn->next = temp->next;
	newn->next->prev = newn;
	temp->next = newn;
	newn->prev = temp;

	return TRUE;
}

BOOL Doubly_Linear::DeleteFirst()
{
	if (head == NULL)
	{
		return FALSE;
	}
	else if(head->next == NULL)
	{
		delete head;
		head = NULL;
		return TRUE;
	}
	else
	{
		head = head->next;
		delete (head->prev);
		head->prev = NULL;
		return TRUE;
	}
}

BOOL Doubly_Linear::DeleteLast()
{
	DPNODE temp = head;

	if (head == NULL)
	{
		return FALSE;
	}
	else if(head->next == NULL)
	{
		delete head;
		head = NULL;
		return TRUE;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->prev->next = NULL;
		delete temp;
		return TRUE;
	}
}

BOOL Doubly_Linear::DeleteAtPos(int iPos)
{
	DPNODE temp = head;

	if ((iPos < 1) || (iPos > Count()))
	{
		return FALSE;
	}
	if (iPos == 1)
	{
		return(DeleteFirst());
	}
	if (iPos == Count())
	{
		return(DeleteLast());
	}

	while (iPos > 2)
	{
		temp = temp->next;
		iPos--;
	}
	temp->next = temp->next->next;
	delete (temp->next->prev);
	temp->next->prev = temp;
	return TRUE;
}

void Doubly_Linear::DisplayForward()
{
	DPNODE temp = head;

	if (head == NULL)
	{
		cout << "Linked list empty\n";
		return;
	}

	while (temp != NULL)
	{
		cout << temp->data << "\t";
		temp = temp->next;
	}
	cout << "\n";
}

void Doubly_Linear::DisplayBackward()
{
	DPNODE temp = head;

	if (head == NULL)
	{
		cout << "Linked list empty\n";
		return;
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	while (temp != NULL)
	{
		cout << temp->data << "\t";
		temp = temp->prev;
	}
	cout << "\n";
}

int Doubly_Linear::Count()
{
	DPNODE temp = head;
	int iCnt = 0;

	if (head == NULL)
	{
		return iCnt;
	}

	while (temp != NULL)
	{
		iCnt++;
		temp = temp->next;
	}
	return iCnt;
}

Doubly_Linear::~Doubly_Linear()
{

}

extern "C"
{
	Doubly_Linear* createDoubly_Linear()
	{
		return new Doubly_Linear;
	}

	void destroyDoubly_Linear(Doubly_Linear *p)
	{
		delete p;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////

Doubly_Circular::Doubly_Circular()
{
	head = NULL;
	tail = NULL;
}

BOOL Doubly_Circular::InsertFirst(int iNo)
{
	DPNODE temp = head, newn = NULL;
	
	newn = new DNODE;

	if (newn == NULL)
	{
		return FALSE;
	}

	newn->data = iNo;
	newn->next = NULL;
	newn->prev = NULL;

	if ((head == NULL) && (tail == NULL))
	{
		head = tail = newn;
		tail->next = newn;
		head->prev = newn;
		return TRUE;
	}
	else
	{
		head->prev = newn;
		newn->next = head;
		head = newn;
		tail->next = head;
		head->prev = tail;
		return TRUE;
	}
}

BOOL Doubly_Circular::InsertLast(int iNo)
{
	DPNODE newn = NULL;
	newn = new DNODE;

	if (newn == NULL)
	{
		return FALSE;
	}
	newn->data = iNo;
	newn->next = NULL;
	newn->prev = NULL;

	if ((head == NULL) && (tail == NULL))
	{
		head = tail = newn;
		tail->next = head;
		head->prev = tail;
		return TRUE;
	}
	else
	{
		tail->next = newn;
		newn->prev = tail;
		tail = newn;
		tail->next = head;
		head->prev = tail;
		return TRUE;
	}
}

BOOL Doubly_Circular::InsertAtPos(int iNo, int iPos)
{
	DPNODE temp = head;
	DPNODE newn = NULL;

	if ((iPos < 1) || (iPos > (Count() + 1)))
	{
		return FALSE;
	}
	if (iPos == 1)
	{
		return(InsertFirst(iNo));
	}
	if (iPos == (Count() + 1))
	{
		return(InsertLast(iNo));
	}

	newn = new DNODE;
	if (newn == NULL)
	{
		return FALSE;
	}
	newn->data = iNo;
	newn->next = NULL;
	newn->prev = NULL;

	while (iPos > 2)
	{
		temp = temp->next;
		iPos--;
	}
	newn->next = temp->next;
	temp->next->prev = newn;
	newn->prev = temp;
	temp->next = newn;

	return TRUE;
}

BOOL Doubly_Circular::DeleteFirst()
{
	if ((head == NULL) && (tail == NULL))
	{
		return FALSE;
	}
	if (head == tail)
	{
		delete head;
		head = tail = NULL;
		return TRUE;
	}
	head = head->next;
	delete (tail->next);
	tail->next = head;
	head->prev = tail;

	return TRUE;
}

BOOL Doubly_Circular::DeleteLast()
{
	if ((head == NULL) && (tail == NULL))
	{
		return FALSE;
	}
	if (head == tail)
	{
		delete tail;
		head = tail = NULL;
		return TRUE;
	}
	tail = tail->prev;
	delete (tail->next);
	tail->next = head;
	head->prev = tail;

	return TRUE;
}

BOOL Doubly_Circular::DeleteAtPos(int iPos)
{
	DPNODE temp = head;

	if ((iPos < 1) || (iPos > Count()))
	{
		return FALSE;
	}
	if (iPos == 1)
	{
		return(DeleteFirst());
	}
	if (iPos == Count())
	{
		return(DeleteLast());
	}

	while (iPos > 2)
	{
		temp = temp->next;
		iPos--;
	}
	temp->next = temp->next->next;
	delete (temp->next->prev);
	temp->next->prev = temp;

	return TRUE;
}

void Doubly_Circular::DisplayForward()
{
	DPNODE temp = head;

	if ((head == NULL) && (tail == NULL))
	{
		cout << "Empty linked list\n";
		return;
	}

	do
	{
		cout << temp->data<<"\t";
		temp = temp->next;
	} while (temp != tail->next);
	cout << "\n";
}

void Doubly_Circular::DisplayBackward()
{
	DPNODE temp = tail;

	if ((head == NULL) && (tail == NULL))
	{
		cout << "Empty linked list\n";
		return;
	}

	do
	{
		cout << temp->data << "\t";
		temp = temp->prev;
	} while (temp != head->prev);
	cout << "\n";
}

int Doubly_Circular::Count()
{
	DPNODE temp = head;
	int iCnt = 0;

	if ((head == NULL) && (tail == NULL))
	{
		return iCnt;
	}

	do
	{
		iCnt++;
		temp = temp->next;
	} while (temp != tail->next);

	return iCnt;
}

Doubly_Circular::~Doubly_Circular()
{
	DPNODE temp = head;

	while (temp != tail)
	{
		temp = temp->next;
		delete head;
		head = temp;
	}
	delete head;
}

extern "C"
{
	Doubly_Circular* createDoubly_Circular()
	{
		return new Doubly_Circular;
	}

	void destroyDoubly_Circular(Doubly_Circular *p)
	{
		delete p;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Name		:	Stack
// Author	:	Nalin
// Input	:	Nothing
// Output	:	Nothing
// Description:	It is constructor of Stack class
///////////////////////////////////////////////////////////////////////////////////////////////////

Stack::Stack()
{
	head = tail = NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Name		:	IsStackEmpty
// Author	:	Nalin
// Input	:	Nothing
// Output	:	BOOL
//				returns true if stack is empty
//				returns false if stack contains at least one element
// Description:	It is used to check wheather Stack is empty or not
///////////////////////////////////////////////////////////////////////////////////////////////////

BOOL Stack::IsStackEmpty()
{
	if ((head == NULL) && (tail == NULL))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Name		:	Push
// Author	:	Nalin
// Input	:	T iNo	:	It is element which is to added in stack
// Output	:	Nothing
// Description:	It is used to insert element into Stack
///////////////////////////////////////////////////////////////////////////////////////////////////

void Stack::Push(int iNo)
{
	DPNODE newn = NULL;
	newn = new DNODE;

	if (newn == NULL)
	{
		return;
	}
	newn->data = iNo;
	newn->next = NULL;
	newn->prev = NULL;

	if (IsStackEmpty() == TRUE)
	{
		head = tail = newn;
	}
	else
	{
		tail->next = newn;
		newn->prev = tail;
		tail = newn;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Name		:	Pop
// Author	:	Nalin
// Input	:	Nothing
// Output	:	element of specific type
// Description:	It is used to delete element from Stack
///////////////////////////////////////////////////////////////////////////////////////////////////


int Stack::Pop()
{
	int iNo;

	if (IsStackEmpty() == TRUE)
	{
		return -1;
	}
	iNo = tail->data;
	tail = tail->prev;
	delete (tail->next);
	tail->next = NULL;

	return iNo;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Name		:	Display
// Author	:	Nalin
// Input	:	Nothing
// Output	:	Nothing
// Description:	It is used to display elements of Stack
///////////////////////////////////////////////////////////////////////////////////////////////////


void Stack::Display()
{
	DPNODE temp = head;

	//cout << "\n Stack : ";
	while (temp != NULL)
	{
		cout << temp->data << "\t";
		temp = temp->next;
	}
	cout << "\n";
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Name		:	~Stack
// Author	:	Nalin
// Input	:	Nothing
// Output	:	Nothing
// Description:	It is destructor of Stack class
///////////////////////////////////////////////////////////////////////////////////////////////////


Stack::~Stack()
{
	DPNODE temp = head;

	while (temp != NULL)
	{
		temp = temp->next;
		delete head;
		head = temp;
	}
}

extern "C"
{
	Stack* createStack()
	{
		return new Stack;
	}

	void destroyStack(Stack *p)
	{
		delete p;
	}
}

/*
Functions Defination of class Queue
*/

///////////////////////////////////////////////////////////////////////////////////////////////////
// Name		:	Queue
// Author	:	Nalin
// Input	:	Nothing
// Output	:	Nothing
// Description:	It is constructor of class Queue
///////////////////////////////////////////////////////////////////////////////////////////////////


Queue::Queue()
{
	head = tail = NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Name		:	IsQueueEmpty
// Author	:	Nalin
// Input	:	Nothing
// Output	:	BOOL
//				returns true if queue is empty
//				returns false if queue contains atleast one element
// Description:	It is used to check wheather queue is empty or not
///////////////////////////////////////////////////////////////////////////////////////////////////


BOOL Queue::IsQueueEmpty()
{
	if ((head == NULL) && (tail == NULL))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Name		:	Enqueue
// Author	:	Nalin
// Input	:	T iNo	:	It is element which is to added in queue
// Output	:	Nothing
// Description:	It is used to insert element into Queue
///////////////////////////////////////////////////////////////////////////////////////////////////


void Queue::Enqueue(int iNo)
{
	PNODE newn = NULL;
	newn = new NODE ;
	
	if (newn == NULL)
	{
		return;
	}
	newn->data = iNo;
	newn->next = NULL;

	if (IsQueueEmpty() == TRUE)
	{
		head = tail = newn;
	}
	else
	{
		tail->next = newn;
		tail = newn;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Name		:	Dequeue
// Author	:	Nalin
// Input	:	Nothing
// Output	:	element of specific datatype
// Description:	It is used to remove element from Queue
///////////////////////////////////////////////////////////////////////////////////////////////////


int Queue::Dequeue()
{
	int iNo;
	PNODE temp = head;

	if (IsQueueEmpty() == TRUE)
	{
		return -1;
	}
	iNo = head->data;
	head = head->next;
	delete temp;

	return iNo;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Name		:	Display
// Author	:	Nalin
// Input	:	Nothing
// Output	:	Nothing
// Description:	It is used to display element from Queue
///////////////////////////////////////////////////////////////////////////////////////////////////


void Queue::Display()
{
	PNODE temp = head;

	//cout << "\n Queue :";
	while (temp != NULL)
	{
		cout << temp->data << "\t";
		temp = temp->next;
	}
	cout << "\n";
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Name		:	~Queue
// Author	:	Nalin
// Input	:	Nothing
// Output	:	Nothing
// Description:	It is destructor of class Queue
///////////////////////////////////////////////////////////////////////////////////////////////////


Queue::~Queue()
{
	PNODE temp = head;

	while (temp != NULL)
	{
		temp = temp->next;
		delete head;
		head = temp;
	}
}

extern "C"
{
	Queue* createQueue()
	{
		return new Queue;
	}

	void destroyQueue(Queue *p)
	{
		delete p;
	}
}
