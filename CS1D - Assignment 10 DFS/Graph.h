/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY & TALON BAKER
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 4/2/2015
 * ASIGNMENT #     : 10
 * ASSIGNMENT NAME : DFS
 *******************************************************************************/
#ifndef GRAPH_H_
#define GRAPH_H_
#define INFINITY 9999
#include<iostream>
#include <list>

using namespace std;

// Adjacency Matrix
int inMatrix[12][12] = {{0,381,9999,1015,9999,1435,9999,9999,9999,9999,9999,9999},

						{381,0,807,1267,9999,9999,9999,9999,9999, 9999, 9999, 9999},

						{9999, 807, 0, 1331, 9999, 9999, 9999, 2097, 9999, 9999, 9999, 9999},

						{1015, 1267, 1331, 0, 9999, 9999, 599, 1003, 9999, 9999, 9999, 9999},

						{9999, 9999, 9999, 9999, 0, 239, 9999, 9999, 1187, 810, 9999, 9999},

						{1435, 9999, 9999, 9999, 239, 0, 496, 9999, 9999, 781, 9999, 9999},

						{1663, 9999, 9999, 599, 9999, 496, 0,533, 9999, 864, 1260, 9999},

						{9999, 9999, 2097, 1003, 9999, 9999, 533, 0, 9999, 9999, 787, 983},

						{9999, 9999, 9999, 9999, 1187, 9999, 9999, 9999, 0, 661, 9999, 9999},

						{9999, 9999, 9999, 9999, 810, 781, 864, 9999, 661, 0, 888, 9999},

						{9999, 9999, 9999, 9999, 9999, 9999, 1260, 787, 9999, 888, 0, 214},

						{9999, 9999, 9999, 9999, 9999, 9999, 9999, 983, 9999, 9999, 214, 0}};

// Aiport Cities
string AirPorts[12]={"LOS_ANGELES",
					"SAN_FRAN",
				    "SEATTLE",
					"DENVER",
					"HOUSTON",
					"DALLAS",
					"KANSAS_CITY",
					"CHICAGO",
					"MIAMI",
					"ATLANTA",
					"NEW_YORK",
					"BOSTON"};

// Graph utilizing Dijkstra's Algorithm
class Dijkstra
{
	public:
		    void initArray();
			void read();
			void initialize();
			int getClosestUnmarkedNode();
			void calculateDistance();
			void output();
			void printPath(int);

	private:
			int adjMatrix[12][12];
			int predecessor[15],distance[15];
			bool mark[15];
			int source;
			int numOfVertices;


};


// Initializes the matrix
void Dijkstra::initialize()
{
	numOfVertices = 12;
	source = 0;
    for(int i=0;i<numOfVertices;i++)
    {
        mark[i] = false;
        predecessor[i] = -1;
        distance[i] = INFINITY;
    }
    distance[source]= 0;
}

// Finds the closest unmarked node
int Dijkstra::getClosestUnmarkedNode()
{
    int minDistance = INFINITY;
    int closestUnmarkedNode;
    for(int i=0;i<numOfVertices;i++)
    {
        if((!mark[i]) && ( minDistance >= distance[i]))
        {
            minDistance = distance[i];
            closestUnmarkedNode = i;
        }
    }
    return closestUnmarkedNode;
}

// Calculates the shortest distance
void Dijkstra::calculateDistance()
{
    initialize();
    int closestUnmarkedNode;
    int count = 0;
    while(count < numOfVertices)
    {
        closestUnmarkedNode = getClosestUnmarkedNode();
        mark[closestUnmarkedNode] = true;
        for(int i=0;i<numOfVertices;i++) {
            if((!mark[i]) && (inMatrix[closestUnmarkedNode][i]>0) )
            {
                if(distance[i] > distance[closestUnmarkedNode]+inMatrix[closestUnmarkedNode][i])
                {
                    distance[i] = distance[closestUnmarkedNode]+inMatrix[closestUnmarkedNode][i];
                    predecessor[i] = closestUnmarkedNode;
                }
            }
        }
        count++;
    }
}

// Prints the flight path - recursive function
void Dijkstra::printPath(int node)
{
    if(node == source)
        cout<< AirPorts[node] <<"..";
    else if(predecessor[node] == -1)
        cout<<"No path from “<<source<<”to "<<AirPorts[node] <<endl;
    else
    {
        printPath(predecessor[node]);
        cout<<AirPorts[node]<<"..";
    }
}

// Outputs flight path
void Dijkstra::output()
{
    for(int i=0;i<numOfVertices;i++)
    {
        if(i == source)
            cout<<AirPorts[source]<<".."<<AirPorts[source];
        else
            printPath(i);
        cout << endl << "DISTANCE: "<<distance[i] << " MILES" << endl << endl;
    }
}

#endif /* GRAPH_H_ */
