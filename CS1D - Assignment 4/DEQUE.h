/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 2/17/2015
 * ASIGNMENT #     : 4
 * ASSIGNMENT NAME : Queue-DeQue Vector
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
			int size();
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
			void front();
			void insert(int value, int insertPoint);
			// display: displays contents of deque
			void display();
	private:
			// head: keeps track of head of queue
			node<data> *head;
			// tail: keeps track of tail of queue
			node<data> *tail;

			int queueSize;

};

// Default constructor
template <typename data>
DEQUE<data>::DEQUE()
:head(NULL), tail(NULL), queueSize(0)
{}

// Destructor
template <typename data>
DEQUE<data>::~DEQUE()
{}

template <typename data>
int DEQUE<data>::size()
{
	return queueSize;
}
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

	queueSize ++;
}

// pop_front: removes from front of deque
template <typename data>
void DEQUE<data>::pop_front()
{
	if(isEmpty())
	{
		cout << "Can't dequeue from an empty list!\n";
	}
	else if((head == tail))
	{
		delete head;
		head = NULL;
		tail = NULL;

		queueSize --;
	}
	else
	{
		node<data> *current;
		current = tail->prev;
		delete tail;
		tail = current;
		current->next = NULL;
		tail = current;
		queueSize --;
	}
}

// pop_back: removes from back of deque
template <typename data>
void DEQUE<data>::pop_back()
{
	if(isEmpty())
	{
		cout << "Empty!\n";
	}
	else if((head == tail))
	{
		delete head;
		head = NULL;
		tail = NULL;

		queueSize --;
	}
	else
	{
		node<data> *current;
		current = head->next;
		delete head;
		head = current;
		current->prev = NULL;
		head = current;
		queueSize --;

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

template<typename data>
void DEQUE<data>::front()
{
	node<data> *temp;
	temp = tail;
	if(isEmpty())
	{
		cout << "Empty! No Front";
	}
	else
	{
		cout << "Front: " << temp->input;
	}
}

template <typename data>
void DEQUE<data>::insert(int value, int insertPoint)
{
	node<data> *temp;
	node <data> *last;
	last = tail;

	if(insertPoint > size() || insertPoint < 0)
	{
		cout << "Out of bounds input1\n";
	}
	else
	{
		if(insertPoint == 0)
		{
			push_front(value);
		}
		else if(insertPoint == size())
		{
			push_back(value);
		}
		else
		{
			for(int i = 0 ; i < insertPoint -1; i ++)
			{
				last = last->prev;
			}

			temp = new node<data>;
			temp->input = value;
			last ->prev ->next = temp;
			temp -> prev = last -> prev;
			last ->prev = temp;
			temp->next = last;
		}

		queueSize ++;
	}



}
// display: displays contents of deque
template<typename data>
void DEQUE<data>::display()
{
	int index = 1;
	node<data> *temp;
	temp = tail;
	if(isEmpty())
	{
		cout << "Cant display an empty queue\n";
	}
	else
	{
		cout << endl;
		while(temp != NULL)
		{
			cout << index <<": "<< temp->input << endl;
			temp = temp->prev;
			index ++;
		}
	}

}
#endif /* DOUBLYLINKEDLIST_H_ */
