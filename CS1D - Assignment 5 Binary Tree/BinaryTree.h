/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1D SPRING 2015
 * DATE       	   : 2/24/2015
 * ASIGNMENT #     : 5
 * ASSIGNMENT NAME : Binary Trees
 ******************************************************************************/
#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include<iostream>
using namespace std;

/* node */
struct treeNode
{
	treeNode *left;
	treeNode *right;
	char data;
};


class BinaryTree
{

	public:
			// constructor
			BinaryTree();
			// desctructor
			~BinaryTree();
			// isempty: checks if tree is empty
			bool isempty();
			// insert: inserts a character into next node
			void insert(char item);
			void postordertrav();
			// postorder: outputs nodes of trees
			void postorder(treeNode *ptr);
			void preordertrav();
			// preorder: outputs nodes of trees
			void preorder(treeNode *ptr);
			// root: root of tree

	private:
			treeNode *root;
};

// default contructor
BinaryTree::BinaryTree()
:root(NULL)
{}

// destructor
BinaryTree::~BinaryTree()
{}

// checks if the root == NULL
bool BinaryTree::isempty()
{
	return root == NULL;
}

// Inserts a new character into the next node
void BinaryTree::insert(char item)
{
	// creates a new node, sets p-> data to item, points left and right to NULL
	treeNode *p = new treeNode;
	p->data  = item;
	p->left  = NULL;
	p->right = NULL;

	// if tree is empty, p is now the root
	if(isempty())
	{
		root = p;
	}
	// if tree is not empty, add to next node
	else
	{
		// parent node, point to NULL
		treeNode *parent;
		parent = NULL;
		// ptr node, point to the root of binary tree
		treeNode *ptr;
		ptr = root;

		// iterates through tree, looks for next node
		while(ptr!=NULL)
		{
			// parent equals ptr
			parent = ptr;
			if(item > ptr->data)
			{
				ptr = ptr->right;
			}
			else
			{
				ptr = ptr->left;
			}
		}

		if(item < parent->data)
		{
			parent->left = p;
		}
		else
		{
			parent->right = p;
		}

	}
}

void BinaryTree::postordertrav()
{
	postorder(root);
}
// prints tree using postorder traversal
void BinaryTree::postorder(treeNode *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout<< " " << ptr->data << " ";
	}
}
void BinaryTree::preordertrav()
{
	preorder(root);
}
// prints tree using preorder traversal
void BinaryTree::preorder(treeNode *ptr)
{
	if(ptr!=NULL)
	{
		cout<< " " << ptr->data << " ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
#endif
