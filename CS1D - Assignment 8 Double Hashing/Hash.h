/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 3/17/2015
 * ASIGNMENT #     : 8
 * ASSIGNMENT NAME : Double Hashing
 *******************************************************************************/
#ifndef HASH_H_
#define HASH_H_
#include <iostream>
using namespace std;

// city and number struct
struct element
{
	int num;
	string city;
};

// returns location in bucket array
int hashFunction(element entry)
{
	int first;
	int second;

	first = entry.num%19;
	second = 17 -(entry.num%17);

	return first + second;
}
// deletes location in bucket array
int deleteEntry(int entry)
{
	int first;
	int second;

	first = entry%19;
	second = 17 -(entry%17);

	return first + second;
}



#endif /* HASH_H_ */
