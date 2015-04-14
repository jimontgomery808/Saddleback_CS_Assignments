/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 2/10/2015
 * ASIGNMENT #     : 3
 * ASSIGNMENT NAME : Stacks and Deques
 ******************************************************************************/
#include "header.h"

#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

/* NODE of Singly Linked List */
template<typename data>
struct Node
{
	data input;
	Node *next;
};

/******************************************************************************
 Class: Singly Linked List Stack
 ______________________________________________________________________________
 This class implements a Singly Linked List as a stack
 ******************************************************************************/
template<typename data>
class S_LIST
{
	public:
			// Constructor
			S_LIST();
			// Desctructor
			~S_LIST();
			// initiate: initiates the values of the stack from an array
			void initiate(data inArray[], int size);
			// push: adds data to top of stack
			void push(data pushData);
			// pop: removes the top of the stack
			void pop();
			// top: returns top of stack
			data top();
			// isEmpty: checks if stack is empty
			bool isEmpty();
			// display: displays contents of stack
			void display();
	private:
			// head: bottom of stack
			Node<data> *head;
			// tail: top of stack
			Node<data> *tail;
};

template<typename data>
S_LIST<data>::S_LIST()
:head(NULL), tail(NULL)
{}

template<typename data>
S_LIST<data>::~S_LIST()
{
	delete head;
	delete tail;
}

template<typename data>
void S_LIST<data>::initiate(data inArray[], int size)
{
	for(int i = 0; i < size; i ++)
	{
		push(inArray[i]);
	}
}
template<typename data>
void S_LIST<data>::push(data pushData)
{
	Node<data> *temp;
	temp = new Node<data>;
	temp->input = pushData;

	if(isEmpty())
	{
		head = temp;
		temp->next = NULL;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
		temp->next = NULL;
	}

}

template<typename data>
void S_LIST<data>::pop()
{
	if(isEmpty())
	{
		cout << "Can't pop from an empty list!\n";
	}
	if(!isEmpty() && (head == tail))
	{
		delete head;
		head = NULL;
		tail = NULL;
	}
	else
	{
		Node<data> *current;
		current = head;
		while(current->next != tail)
		{
			current = current->next;
		}
		delete tail;
		tail = current;
		current->next = NULL;
	}
}

template<typename data>
bool S_LIST<data>::isEmpty()
{
	return head == NULL;
}

template <typename data>
data S_LIST<data>::top()
{
	Node<data> *temp;
	temp = tail;
	return temp->input;
}
template<typename data>
void S_LIST<data>::display()
{
	int index = 1;
	Node<data> *temp;
	temp = head;
	while(temp != NULL)
	{
		cout << index << ": " << temp->input << endl;
		temp = temp->next;
		index ++;
	}
}
#endif /* SINGLYLINKEDLIST_H_ */
