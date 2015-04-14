/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 2/24/2015
 * ASIGNMENT #     : 5
 * ASSIGNMENT NAME : Binary Trees
 ******************************************************************************/
#include "BinaryTree.h"
/*******************************************************************************
 * ASSIGNMENT 5: Binary Trees
 * _____________________________________________________________________________
 *
 *This program will implement the Binary Tree ADT via linked list
 ******************************************************************************/
int main()
{
	/* Binary Tree */
	BinaryTree myTree;
	char inChar;

	/* Insert values into tree nodes */
	for(int i = 0; i < 7; i ++)
	{
		cout << "Enter a letter to add to Binary Tree: ";
		cin.get(inChar);
		myTree.insert(inChar);
		cin.ignore();
	}

	/* OUTPUT - postorder traversal */
	cout << endl << "Outputting tree using post order traversal: " << endl;
	myTree.postordertrav();

	/* OUTPUT - preorder traversal */
	cout << endl << "Outputting tree using preorder traversal: " << endl;
	myTree.preordertrav();

    return 0;
}
