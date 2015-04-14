/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 2/10/2015
 * ASIGNMENT #     : 3
 * ASSIGNMENT NAME : Stacks and Deques
 ******************************************************************************/
#include "DEQUE.h"
#include "header.h"
#include "SinglyLinkedList.h"

string ReturnParenthesis(string inString);

/******************************************************************************
 Function: CheckEquation
 ______________________________________________________________________________
 This function will check if a set of parenthesis, brackets, and french braces
 are part of a valid equation format
 ******************************************************************************/
void CheckEquation(string inString)
{
	// Singly List List
	S_LIST<char> charList;
	// Storing just parenthesis, brackets, and/or french braces
	string checkString = ReturnParenthesis(inString);

	// If uneven number of elements, == false
	if(checkString.length()%2 != 0)
	{
		cout << inString << ": INVALID EQUATION" << endl;
	}
	else
	{
		// Iterates through the elements. Pushes opening
		// parenthesis/brackets/french braces, then pops if it reaches it's
		// counter part
		for(unsigned int i = 0; i < checkString.length(); i ++)
		{
			if(checkString[i] == '{' || checkString[i] == '('
			   || checkString[i] == '[')
			{
				charList.push(checkString[i]);
			}
			else if(checkString[i] == '}')
			{
				if(charList.top() == '{')
				{
					charList.pop();
				}
			}
			else if(checkString[i] == ')')
			{
				if(charList.top() == '(')
				{
					charList.pop();
				}
			}
			else if(checkString[i] == ']')
			{
				if(charList.top() == '[')
				{
					charList.pop();
				}
			}
		}

		// At end, if list is empty, all elements have a counter part,
		// therefore the equation is valid. Else, it is false
		if(charList.isEmpty())
		{
			cout << inString << ": VALID EQUATION" << endl;

		}
		else
		{
			cout << inString << ": INVALID EQUATION" << endl;
		}
	}

}
/******************************************************************************
 Function: ReturnParenthesis
 ______________________________________________________________________________
 This function will accept an equation in the form of a string, and return only
 parenthesis/brackets/braces, in order
 ******************************************************************************/
string ReturnParenthesis(string inString)
{
	string returnString;
	for(unsigned int i = 0; i < inString.length(); i ++)
	{
		if(inString[i] == '('
	      || inString[i] == ')'
		  || inString[i] == '{'
		  || inString[i] == '}'
		  || inString[i] == '['
		  || inString[i] == ']')
		{
			returnString += inString[i];
		}
	}

	return returnString;
}

