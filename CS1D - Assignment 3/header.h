/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 2/10/2015
 * ASIGNMENT #     : 3
 * ASSIGNMENT NAME : Stacks and Deques
 ******************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;


/* FUNCTION DisplayVector: displays contents of a vector */
template<class data>
void DisplayVector(vector<data> &inVector)
{
	for(unsigned int i = 0; i < inVector.size(); i ++)
	{
		cout << i + 1 << ": " << inVector[i] << endl;
	}
}

#endif /* HEADER_H_ */
