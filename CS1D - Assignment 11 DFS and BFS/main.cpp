/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 4/7/2015
 * ASIGNMENT #     : 11
 * ASSIGNMENT NAME : DFS & BFS
 *******************************************************************************/
#include "DFS.h"
#include "BFS.h"
/*******************************************************************************
 * Assignment 11- DFS & BFS
 * ____________________________________________________________________________
 * This assignment will perform a Depth First Search and a Breadth First Search
 * on a graph.
 *******************************************************************************/
int main()
{
	// Depth First Graph
	Graph g(12);
	// Adding all edges
	g.addEdge(0,3);
	g.addEdge(0,6);
	g.addEdge(1,0);
	g.addEdge(2,1);
	g.addEdge(2,3);
	g.addEdge(3,7);
	g.addEdge(3,1);
	g.addEdge(4,5);
	g.addEdge(4,9);
	g.addEdge(5,6);
	g.addEdge(5,9);
	g.addEdge(5,0);
	g.addEdge(6,9);
	g.addEdge(6,10);
	g.addEdge(6,7);
	g.addEdge(6,3);
	g.addEdge(6,0);
	g.addEdge(7,2);
	g.addEdge(7,11);
	g.addEdge(8,4);
	g.addEdge(9,8);
	g.addEdge(10,7);
	g.addEdge(10,9);
	g.addEdge(11,10);

	cout << "Depth First Search\n"
			"----------------------------------------------------------------\n";
	g.DFS(11);
	cout << "END";

	// Breadth First Graph
	BFSGraph b(12);
	// Adding all edges
	b.addEdge(0,3);
	b.addEdge(0,6);
	b.addEdge(1,0);
	b.addEdge(2,1);
	b.addEdge(2,3);
	b.addEdge(3,7);
	b.addEdge(3,1);
	b.addEdge(4,5);
	b.addEdge(4,9);
	b.addEdge(5,6);
	b.addEdge(5,9);
	b.addEdge(5,0);
	b.addEdge(6,9);
	b.addEdge(6,10);
	b.addEdge(6,7);
	b.addEdge(6,3);
	b.addEdge(6,0);
	b.addEdge(7,2);
	b.addEdge(7,11);
	b.addEdge(8,4);
	b.addEdge(9,8);
	b.addEdge(10,7);
	b.addEdge(10,9);
	b.addEdge(11,10);

	cout << "\n\nBreadth First Search\n"
			"----------------------------------------------------------------\n";
	b.BFS(11);
	cout << "END";

}
