#include"Header.h"
#include<dlfcn.h>

int main()
{
	void *p = NULL;
	Singly_Linear *ptr1 = NULL;
	Singly_Circular *ptr2 = NULL;
	Doubly_Linear *ptr3 = NULL;
	Doubly_Circular *ptr4 = NULL;
	Stack *ptr5 = NULL;
	Queue *ptr6 = NULL;
	
	Singly_Linear* (*fp1)() = NULL;
	void (*fp2)(Singly_Linear *) = NULL;
	
	Singly_Circular* (*fp3)() = NULL;
	void (*fp4)(Singly_Circular *) = NULL;
	
	Doubly_Linear* (*fp5)() = NULL;
	void (*fp6)(Doubly_Linear *) = NULL;
	
	Doubly_Circular* (*fp7)() = NULL;
	void (*fp8)(Doubly_Circular *) = NULL;
	
	Stack* (*fp9)() = NULL;
	void (*fp10)(Stack *) = NULL;
	
	Queue* (*fp11)() = NULL;
	void (*fp12)(Queue *) = NULL;
	
	p = dlopen("/home/nalin/Industrial_Project_Development/DataStructure Library Development/library.so", RTLD_LAZY);
	if(!p)
	{
		cout<<"Unable to load library"<<endl;
		return -1;
	}
	
	/*Singly Linear Linked list*/
	fp1 = (Singly_Linear* (*)())dlsym(p, "createSingly_Linear");
	if(!fp1)
	{
		cout<<"Unable to get function address"<<endl;
		return -1;
	}

	ptr1 = fp1();
	cout << "Singly Linear Linked list \n";
	ptr1->InsertFirst(20);
	ptr1->InsertFirst(10);

	ptr1->InsertLast(30);
	ptr1->InsertLast(40);

	ptr1->InsertAtPos(15, 2);

	ptr1->Display();

	ptr1->DeleteFirst();

	ptr1->DeleteLast();

	ptr1->DeleteAtPos(2);

	ptr1->Display();
	
	fp2 = (void (*)(Singly_Linear *))dlsym(p, "destroySingly_Linear");
	if(!fp2)
	{
		cout<<"Unable to get function address"<<endl;
		return -1;
	}
	fp2(ptr1);
	
	/*Singly Circular Linked List*/
	fp3 = (Singly_Circular* (*)())dlsym(p, "createSingly_Circular");
	if(!fp3)
	{
		cout<<"Unable to get function address"<<endl;
		return -1;
	}

	ptr2 = fp3();
	cout << "Singly Circular Linked list \n";
	ptr2->InsertFirst(20);
	ptr2->InsertFirst(10);

	ptr2->InsertLast(30);
	ptr2->InsertLast(40);

	ptr2->InsertAtPos(15, 2);

	ptr2->Display();

	ptr2->DeleteFirst();

	ptr2->DeleteLast();

	ptr2->DeleteAtPos(2);

	ptr2->Display();
	
	fp4 = (void (*)(Singly_Circular *))dlsym(p, "destroySingly_Circular");
	if(!fp4)
	{
		cout<<"Unable to get function address"<<endl;
		return -1;
	}
	fp4(ptr2);

	/*Doubly Linear Linked List*/
	fp5 = (Doubly_Linear* (*)())dlsym(p, "createDoubly_Linear");
	if(!fp5)
	{
		cout<<"Unable to get function address"<<endl;
		return -1;
	}

	ptr3 = fp5();
	cout << "Doubly Linear Linked list \n";
	ptr3->InsertFirst(20);
	ptr3->InsertFirst(10);

	ptr3->InsertLast(30);
	ptr3->InsertLast(40);

	ptr3->InsertAtPos(15, 2);

	ptr3->DisplayForward();

	ptr3->DeleteFirst();

	ptr3->DeleteLast();

	ptr3->DeleteAtPos(2);

	ptr3->DisplayForward();
	
	fp6 = (void (*)(Doubly_Linear *))dlsym(p, "destroyDoubly_Linear");
	if(!fp6)
	{
		cout<<"Unable to get function address"<<endl;
		return -1;
	}
	fp6(ptr3);
	
	/*Doubly Circular Linked List*/
	fp7 = (Doubly_Circular* (*)())dlsym(p, "createDoubly_Circular");
	if(!fp7)
	{
		cout<<"Unable to get function address"<<endl;
		return -1;
	}

	ptr4 = fp7();
	cout << "Doubly Circular Linked list \n";
	ptr4->InsertFirst(20);

	ptr4->InsertFirst(10);

	ptr4->InsertLast(30);
	ptr4->InsertLast(40);

	ptr4->InsertAtPos(15, 2);

	ptr4->DisplayForward();

	ptr4->DeleteFirst();

	ptr4->DeleteLast();

	ptr4->DeleteAtPos(2);

	ptr4->DisplayForward();
	
	fp8 = (void (*)(Doubly_Circular *))dlsym(p, "destroyDoubly_Circular");
	if(!fp8)
	{
		cout<<"Unable to get function address"<<endl;
		return -1;
	}
	fp8(ptr4);
	
	/*Stack*/
	fp9 = (Stack* (*)())dlsym(p, "createStack");
	if(!fp9)
	{
		cout<<"Unable to get function address"<<endl;
		return -1;
	}
	
	ptr5 = fp9();
	cout<<"Stack\n";
	ptr5->Push(10);
	ptr5->Push(20);
	ptr5->Push(30);
	
	ptr5->Display();
	
	cout<<"Poped element : "<<ptr5->Pop()<<endl;
	
	ptr5->Display();
	
	fp10 = (void (*)(Stack *))dlsym(p, "destroyStack");
	if(!fp10)
	{
		cout<<"Unable to get function address"<<endl;
		return -1;
	}
	fp10(ptr5);
	
	/*Queue*/
	fp11 = (Queue* (*)())dlsym(p, "createQueue");
	if(!fp11)
	{
		cout<<"Unable to get function address"<<endl;
		return -1;
	}
	
	ptr6 = fp11();
	cout<<"Queue\n";
	ptr6->Enqueue(10);
	ptr6->Enqueue(20);
	ptr6->Enqueue(30);
	
	ptr6->Display();
	
	cout<<"Dequeued element : "<<ptr6->Dequeue()<<endl;
	
	ptr6->Display();
	
	fp12 = (void (*)(Queue *))dlsym(p, "destroyQueue");
	if(!fp10)
	{
		cout<<"Unable to get function address"<<endl;
		return -1;
	}
	fp12(ptr6);
	
	dlclose(p);

	return 0;
}
