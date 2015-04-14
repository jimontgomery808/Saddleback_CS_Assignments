/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY & TALON BAKER
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 4/2/2015
 * ASIGNMENT #     : 10
 * ASSIGNMENT NAME : DFS
 *******************************************************************************/
#include <algorithm>
#include <iostream>
#include "Graph.h"
using namespace std;
/*******************************************************************************
 * Assignment 10- DFS
 * ____________________________________________________________________________
 * This assignment will perform a Depth First Search on a graph, and find the
 * shortest routes from a source to various airports
 *******************************************************************************/
int main()
{
	// Graph
	Dijkstra G;

	//Calculates the shortest distance
	G.calculateDistance();
	cout << "Depth First Search\n"
			"------------------------------------------\n";

	// Output route
	G.output();

}

