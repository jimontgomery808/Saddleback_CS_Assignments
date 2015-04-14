/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 3/10/2015
 * ASIGNMENT #     : 7
 * ASSIGNMENT NAME : Heaps
 *******************************************************************************/
#ifndef HEAP_H_
#define HEAP_H_

#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

// Heap Class
class Heap
{
	public:
		// Default constructor
		Heap();
		// Destructor
		~Heap();
		// Insert item
		void insert(int element);
		// Delete minimum value
		int deletemin();
		// Print heap
		void print();
		// Return size of heap
		int size() { return heap.size(); }
	private:
		// Left child
		int left(int parent);
		// Righ child
		int right(int parent);
		// Parent of node
		int parent(int child);
		// Comparators
		void heapifyup(int index);
		void heapifydown(int index);
	private:
		vector<int> heap;
};

// Default constructor
Heap::Heap()
{
}
// Destructor
Heap::~Heap()
{
}
// Inserts element into heap
void Heap::insert(int element)
{
	// Pushes value, checks heapifyup
    heap.push_back(element);
    heapifydown(heap.size() - 1);
}

// Deletes minimum value
int Heap::deletemin()
{
    int min = heap.front();
    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();
    heapifydown(0);
    return min;
}

// Prints heap
void Heap::print()
{
    vector<int>::iterator pos = heap.begin();
    cout << "Heap = ";
    while ( pos != heap.end() ) {
        cout << *pos << " ";
        ++pos;
    }
    cout << endl;
}

//
void Heap::heapifyup(int index)
{
    while ( ( index > 0 ) && ( parent(index) >= 0 ) &&
            ( heap[parent(index)] > heap[index] ) )
    {
        int tmp = heap[parent(index)];
        heap[parent(index)] = heap[index];
        heap[index] = tmp;
        index = parent(index);
    }
}

void Heap::heapifydown(int index)
{
    int child = left(index);
    if ( ( child > 0 ) && ( right(index) > 0 ) &&
         ( heap[child] > heap[right(index)] ) )
    {
        child = right(index);
    }
    if ( child > 0 )
    {
        int tmp = heap[index];
        heap[index] = heap[child];
        heap[child] = tmp;
        heapifydown(child);
    }
}

int Heap::left(int parent)
{
    int i = ( parent << 1 ) + 1; // 2 * parent + 1
    return ( i < heap.size() ) ? i : -1;
}

int Heap::right(int parent)
{
    int i = ( parent << 1 ) + 2; // 2 * parent + 2
    return ( i < heap.size() ) ? i : -1;
}

int Heap::parent(int child)
{
    if (child != 0)
    {
        int i = (child - 1) >> 1;
        return i;
    }
    return -1;
}


#endif /* HEAP_H_ */
