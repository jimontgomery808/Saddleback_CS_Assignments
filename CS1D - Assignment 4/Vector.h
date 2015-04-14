/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 2/17/2015
 * ASIGNMENT #     : 4
 * ASSIGNMENT NAME : Queue-DeQue Vector
 ******************************************************************************/
#ifndef VECTOR_H_
#define VECTOR_H_
#include "header.h"
#include "DEQUE.h"
template <typename data>
class Vector
{
	public:
			// constructor
			Vector();
			// intialialize: initializes to size/value
			Vector(int size, int value);
			// destructor
			~Vector();
			// size: returns size of Vector
			int size();
			// empty: returns if Vector is empty
			bool empty();
			// front: returns front of Vector
			void front();
			// push_back: adds to back of Vector
			void push_back(data input);
			// pop_back: removes from back of Vector
			void pop_back();
			// insert: inserts a value at the second parameter
			void insert(int value, int insertPonit);
			// display: displays Vector
			void display();




	private:
			node <data> *head;
			node <data> *tail;
			// DEQUE class
			DEQUE<data> d;
};
// constructor
template <typename data>
Vector<data>::Vector()
:head(NULL), tail(NULL)
{}
// intialialize: initializes to size/value
template <typename data>
Vector<data>::Vector(int size, int value)
:head(NULL), tail(NULL)
{
	for(int i = 0; i < size; i ++)
	{
		d.push_back(value);
	}
}
// destructor
template <typename data>
Vector<data>::~Vector()
{}
// size: returns size of Vector
template <typename data>
int Vector<data>::size()
{
	return d.size();
}
// empty: returns if Vector is empty
template <typename data>
bool Vector<data>::empty()
{
	return d.isEmpty();
}
// front: returns front of Vector
template <typename data>
void Vector<data>::front()
{
	d.front();
}
// push_back: adds to back of Vector
template <typename data>
void Vector<data>::push_back(data input)
{
	d.push_back(input);
}
// pop_back: removes from back of Vector
template <typename data>
void Vector<data>::pop_back()
{
	d.pop_back();
}

template <typename data>
void Vector<data>::insert(int value, int insertPoint)
{
	d.insert(value, insertPoint);
}
// display: displays Vector
template <typename data>
void Vector<data>::display()
{
	d.display();
}
#endif /* VECTOR_H_ */
