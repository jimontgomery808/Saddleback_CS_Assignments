/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 3/2/2015
 * ASIGNMENT #     : 6
 * ASSIGNMENT NAME : Priority Queue
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include "PriorityQueue.h"
using namespace std;

/******************************************************************************
Assignment 6 - Priority Queue
_______________________________________________________________________________
This program will implement a priority queue of my own, and the STL priority
queue
 ******************************************************************************/

// Patient struct
struct patient
{
	string name;
	int hoursWaited;
};

// Comparator class
class LessThan
{
	public:
		bool operator()(patient& a, patient& b)
		{
			return (a.hoursWaited < b.hoursWaited);
		}
};

int main()
{
	int time = 0;

	patient pat[7] = {{"Alice Ailment", 3},
					 {"Irene Ill", 1},
					 {"Sid Sicklly", 4},
					 {"Cathy Coughing", 5},
					 {"Bob Bleeding", 2},
					 {"Frank Feelingbad", 7},
					 {"Sam Sneezing", 5}};

/******************************************************************************
 	 	 	 	 	 	STL IMPLEMENTATION
*******************************************************************************/

	cout << "STL Implementation of Priority Queue: \n\n";
	priority_queue<patient, vector<patient>, LessThan> pq;

	for(int i = 0; i < 7; i ++)
	{
		if(time == 90)
		{
			patient urgent1 = {"Paula Pain", i};
			pq.push(urgent1);
			i--;
		}
		else if(time == 150)
		{
			patient urgent2 = {"Tom Temperature", i};
			pq.push(urgent2);
			i--;
		}
		else
		{
			pq.push(pat[i]);
		}
		time += 30;

	}

	int index = 1;
	time = 0;
	while (!pq.empty())
	{

		patient temp = pq.top();
		cout << index << ". Name: " << temp.name << endl;
		pq.pop();
		index ++;
	}

/******************************************************************************
						MY OWN IMPLEMENTATION
*******************************************************************************/

	cout << "\n\nMy Own Implemenation of Priority Queue: \n\n";
	Priority_Queue myPq;
	for(int i = 0; i < 7; i ++)
	{
		if(time == 90)
		{
			myPq.insert("Paula Pain", i);
			i--;
		}
		else if(time == 150)
		{
			myPq.insert("Tom Temperature", i);
			i--;
		}
		else
		{
			myPq.insert(pat[i].name, pat[i].hoursWaited);
		}
		time += 30;

	}

	myPq.display();
	return 0;
}

