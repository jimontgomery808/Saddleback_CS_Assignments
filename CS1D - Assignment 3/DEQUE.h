/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 2/10/2015
 * ASIGNMENT #     : 3
 * ASSIGNMENT NAME : Stacks and Deques
 ******************************************************************************/
#include "header.h"
#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_


template <typename data>
struct node
{
	data input;
    node *next;
    node *prev;
};

// CLASS - DEQUE
template <typename data>
class DEQUE
{
	public:
			// Constructor
			DEQUE();
			// Destructor
			~DEQUE();
			// push_back: adds element to back of deque
			void push_back(data pushData);
			// push_front: adds element to front of deque
			void push_front(data pushData);
			// pop_front: removes from front of deque
			void pop_front();
			// pop_back: pops from back of DEQUE
			void pop_back();
			// Initiate: add to back of queue
			void initiate(data inArray[], int size);
			// isEmpty: checks if queue is empty
			bool isEmpty();
			// display: displays contents of deque
			void display();
	private:
			// head: keeps track of head of queue
			node<data> *head;
			// tail: keeps track of tail of queue
			node<data> *tail;

};

// Default constructor
template <typename data>
DEQUE<data>::DEQUE()
:head(NULL), tail(NULL)
{}

// Destructor
template <typename data>
DEQUE<data>::~DEQUE()
{}

// push_front: adds to front of deque
template <typename data>
void DEQUE<data>::push_front(data pushData)
{
	// Creates and fills a node with data
	node<data> *temp;
	temp = new node<data>;
	temp->input = pushData;

	// Special condition: deque is empty
	if(isEmpty())
	{
		head = temp;
		head->prev = NULL;
		tail = temp;
		tail->next = NULL;
	}
	// Normal condition
	else
	{
		tail->next = temp;
		temp->prev = tail;
		temp->next = NULL;
	}
	tail = temp;
}

// push_back: adds element to back of deque
template <typename data>
void DEQUE<data>::push_back(data pushData)
{
	node<data> *temp;
	temp = new node<data>;
	temp->input = pushData;

	if(isEmpty())
	{
		head = temp;
		head->prev = NULL;
		tail = temp;
		tail->next = NULL;
	}
	else
	{
		temp->prev = NULL;
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
}

// pop_front: removes from front of deque
template <typename data>
void DEQUE<data>::pop_front()
{
	if(isEmpty())
	{
		cout << "Can't pop from an empty list!\n";
	}
	else
	{
		node<data> *current;
		current = tail->prev;
		delete tail;
		tail = current;
		current->next = NULL;
		tail = current;
	}
}

// pop_back: removes from back of deque
template <typename data>
void DEQUE<data>::pop_back()
{
	if(isEmpty())
	{
		cout << "Can't pop from an empty list!\n";
	}
	else
	{
		node<data> *current;
		current = head->next;
		delete head;
		head = current;
		current->prev = NULL;
		head = current;
	}
}
// initiate: initiates deque from an array
template <typename data>
void DEQUE<data>::initiate(data inArray[], int size)
{
	for(int i = 0; i < size; i ++)
	{
		push_back(inArray[i]);
	}
}
// isEmpty: return if head is pointing to NULL
template <typename data>
bool DEQUE<data>::isEmpty()
{
	return head == NULL;
}
// display: displays contents of deque
template<typename data>
void DEQUE<data>::display()
{
	int index = 1;
	node<data> *temp;
	temp = tail;
	while(temp != NULL)
	{
		cout << index <<": "<< temp->input << endl;
		temp = temp->prev;
		index ++;
	}

}
#endif /* DOUBLYLINKEDLIST_H_ */
