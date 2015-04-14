/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 3/2/2015
 * ASIGNMENT #     : 6
 * ASSIGNMENT NAME : Priority Queue
 ******************************************************************************/
#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;


struct node
{
	int priority;
	string info;
	struct node *link;
};


class Priority_Queue
{

    private:
		node *front;

    public:
		Priority_Queue()
    	{
			front = NULL;
    	}
        void insert(string item, int priority)
        {

            node *tmp, *q;
            tmp = new node;
            tmp->info = item;
            tmp->priority = priority;

            if (front == NULL || priority < front->priority)
            {
            	tmp->link = front;
            	front = tmp;
            }
            else
            {
            	q = front;
            	while (q->link != NULL && q->link->priority <= priority)
            		q=q->link;
            	tmp->link = q->link;
            	q->link = tmp;
            }
        }
        void display()
        {
        	int index = 9;
        	node *ptr;
        	ptr = front;
        	if (front == NULL)
        		cout<<"Queue is empty\n";
        	else
        	{
        		cout<<"Priority       Item\n";
        		while(ptr != NULL)
        		{
        			cout <<index <<"                 "<<ptr->info<<endl;
        			ptr = ptr->link;
        			index --;
        		}
        	}
        }

};
#endif /* PRIORITYQUEUE_H_ */
