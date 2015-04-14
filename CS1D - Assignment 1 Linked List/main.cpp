/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 1/27/2015
 * ASIGNMENT #     : 1
 * ASSIGNMENT NAME : Queue Palindrome
 ******************************************************************************/
#include "Queue.h"
using namespace std;

/*******************************************************************************
 * ASSIGNMENT 1: Queue Palindrome
 * _____________________________________________________________________________
 *
 *This program will convert various strings into a doubly linked list of
 * characters. The isPalindrome method will then check if each word or phrase
 * is a palindrome
 ******************************************************************************/
int main()
{
	// Strings to be converted to queues
	string stringArray[10] = {"dad",
			                  "radar",
			                  "Otto",
			                  "mom",
			                  "tigers",
			                  "A man, a plan, a canal, Panama",
			                  "Isn’t this class cool?",
			                  "Was it a car or a cat I saw?",
			                  "Sit on a potato pan, Otis",
			                  "Saddleback is a great place to learn"};

	// Creates an array of queues
	Queue myQueue[10];

	// OUTPUT - Assignment Header
	PrintAssignmentHeader("JOSH MONTGOMERY",
			              "CS1D SPRING 2015",
			              "1/27/2015",
			               1,
			              "Queue Palindrome",
			              'A');

	cout << endl;

	// OUTPUT - table header
	OutputHeader();

	// CALC -  For loop, will iterate through all strings in stringArray and
	//		   all queues in queueArray
	for(int index = 0; index < 10; index ++)
	{
		// CALC - using the Initiate method, converts each string in stringArray
		//		  into a queue of characters
		myQueue[index].Initiate(stringArray[index]);

		// OUTPUT - Current word/phrase
		cout << stringArray[index];

		// CALC - Checks if word/phrase is a palindrome through the Queue isPalindrome
		// 		  method
		if(myQueue[index].isPalindrome())
		{
			// OUTPUT - if isPalindrome returns true, output 'YES'
			cout << right << setw(44 - stringArray[index].length()) << "YES\n";
			cout << left;
		}
		else
		{
			// OUTPUT - if isPalindrome returns false, output 'NO'
			cout << right << setw(43 - stringArray[index].length()) << "NO\n";
			cout << left;
		}
	}
	return 0;
}
