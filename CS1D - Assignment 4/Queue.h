/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 2/17/2015
 * ASIGNMENT #     : 4
 * ASSIGNMENT NAME : Queue-DeQue Vector
 ******************************************************************************/
#ifndef QUEUE_H_
#define QUEUE_H_
#include "DEQUE.h"


template <typename data>
class Queue
{
	public:
			// constructor
			Queue();
			// desctructor
			~Queue();
			// size: returns size
			int size();
			// empty: returns if Queue is empty
			bool empty();
			// front: returns front of Queue
			void front();
			// enqueue: adds to back of Queue
			void enqueue(data e);
			// dequeue: removes from front of Queue
			void dequeue ();
			// display: displays Queue
			void display();


	private:
			// head: keeps track of head of queue
			node<data> *head;
			// tail: keeps track of tail of queue
			node<data> *tail;

			DEQUE<data> d;

};

// Default constructor
template <typename data>
Queue<data>::Queue()
:head(NULL), tail(NULL)
{}

// Destructor
template <typename data>
Queue<data>::~Queue()
{}

// Returns size
template<typename data>
int Queue<data>::size()
{
	return d.size();
}

// Returns empty
template <typename data>
bool Queue<data>::empty()
{
	return d.isEmpty();
}

// Returns front
template <typename data>
void Queue<data>::front()
{
	d.front();
}

// Adds to back
template <typename data>
void Queue<data>::enqueue(data e)
{
	d.push_back(e);
}

// Removes from front
template <typename data>
void Queue<data>::dequeue()
{
	d.pop_front();
}

// Displays contents
template <typename data>
void Queue<data>::display()
{
	d.display();
}
#endif /* QUEUE_H_ */
