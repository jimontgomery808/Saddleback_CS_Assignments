/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 3/17/2015
 * ASIGNMENT #     : 8
 * ASSIGNMENT NAME : Double Hashing
 *******************************************************************************/
#ifndef DEQUE_H_
#define DEQUE_H_
#include <iostream>
#include "Hash.h"
using namespace std;

struct node
{
	element input;
    node *next;
    node *prev;
};

// CLASS - DEQUE
class DEQUE
{
	public:
			// Constructor
			DEQUE();
			// Destructor
			~DEQUE();
			// push_back: adds element to back of deque
			void push_back(element pushData);
			// push_front: adds element to front of deque
			void push_front(element pushData);
			// pop_front: removes from front of deque
			void pop_front();
			// pop_back: pops from back of DEQUE
			void pop_back();
			// Initiate: add to back of queue
			void initiate(element inArray[], int size);
			// isEmpty: checks if queue is empty
			bool isEmpty();
			// display: displays contents of deque
			int size();
			node* front();
			void clear(int key);
			void display(int index);
	private:
			bool cleared;
			// head: keeps track of head of queue
			node *head;
			// tail: keeps track of tail of queue
			node *tail;

};

// Default constructor
DEQUE::DEQUE()
:head(NULL), tail(NULL), cleared(false)
{}

// Destructor
DEQUE::~DEQUE()
{}

// push_front: adds to front of deque

void DEQUE::push_front(element pushData)
{
	// Creates and fills a node with data
	node *temp;
	temp = new node;
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
void DEQUE::push_back(element pushData)
{
	cleared = false;
	node *temp;
	temp = new node;
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
void DEQUE::pop_front()
{
	if(isEmpty())
	{
		cout << "Can't pop from an empty list!\n";
	}
	else
	{
		node *current;
		current = tail->prev;
		delete tail;
		tail = current;
		current->next = NULL;
		tail = current;
	}
}

// pop_back: removes from back of deque
void DEQUE::pop_back()
{
	if(isEmpty())
	{
		cout << "Can't pop from an empty list!\n";
	}
	else
	{
		node *current;
		current = head->next;
		delete head;
		head = current;
		current->prev = NULL;
		head = current;
	}
}
// initiate: initiates deque from an array
void DEQUE::initiate(element inArray[], int size)
{
	for(int i = 0; i < size; i ++)
	{
		push_back(inArray[i]);
	}
}
// isEmpty: return if head is pointing to NULL
bool DEQUE::isEmpty()
{
	return head == NULL;
}
int DEQUE::size()
{
	int index = 1;
	node *temp;
	temp = head;
	while(temp !=NULL)
	{
		temp = temp->next;
		index ++;
	}

	return index;
}

node* DEQUE::front()
{
	node *temp;
	temp = new node;
	temp = head;
	return temp;
}

void DEQUE::clear(int key)
{
	node *temp;
	temp = head;
	while(temp != NULL)
	{
		if(temp->input.num == key)
		{
			temp->input.num = -1;
			temp->input.city = " ";
		}
		else
		{
			temp = temp->next;
		}
	}
}

// display: displays contents of deque
void DEQUE::display(int index)
{
	cout << index << ":";
	if(isEmpty())
	{
		cout << " " << endl;
	}
	else
	{
		node *temp;
		temp = tail;
		while(temp != NULL)
		{
			if(temp->input.num == -1 && temp->input.city == " ")
			{
				temp = temp->prev;
			}
			else
			{
				cout << temp->input.num << " " << temp->input.city << "->";
				temp = temp->prev;
			}
		}
		cout << endl;
	}

}




#endif /* DEQUE_H_ */
