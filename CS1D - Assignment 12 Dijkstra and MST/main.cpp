/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 4/14/2015
 * ASIGNMENT #     : 12
 * ASSIGNMENT NAME : Dijkstra & MST
 *******************************************************************************/
#include "Dijkstra.h"
#include "MST.h"
#include "header.h"
/*******************************************************************************
 * Assignment 12- Dijkstra & MST
 * ____________________________________________________________________________
 * This assignment will use Dijkstra's algorithm to find the shortest distance
 * between nodes, and will also find the minimum spanning tree (MST)
 *******************************************************************************/
int main()
{
	Dijkstra d;
	d.calculateDistance();
	d.output();
	primMST(inMatrix);
}
