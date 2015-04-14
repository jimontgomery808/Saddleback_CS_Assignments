/******************************************************************************
 * PROGRAMMER 	   : JOSH MONTGOMERY
 * CLASS      	   : CS1C FALL 2014
 * DATE       	   : 11/20/2014
 * ASIGNMENT #     : 13
 * ASSIGNMENT NAME : LINKED LIST
 ******************************************************************************/
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include "header.h"

// Struct: node uses in list
template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

// Linked list class
template<class Type>
class linkedListType
{
public:
	//Override = operator
    const linkedListType<Type>& operator=
          			      (const linkedListType<Type>&);
    // Checks if list is empty
    bool isEmptyList();
    // Prints list
    void print();
    // Returns length of list
    int length();
    // Destroys nodes in list
    void destroyList();
    // Inserts node into the last spot
    void insertLast(const Type& newItem);
    // Deletes node
    void deleteNode(const Type& deleteItem);
    // Reverses contents of list
    void reverseList();
    // Inserts into middle of list
    void insertMiddle(const Type& newItem);
    // Default constructor
    linkedListType();
    // Copy constructor
    linkedListType(const linkedListType<Type>& otherList);
    // Destructor
    ~linkedListType();
   	   

	private:
    nodeType<Type> *first; //pointer to the first node of the list
    nodeType<Type> *last;  //pointer to the last node of the list
};

/******************************************************************************
 * isEmpty
 * ____________________________________________________________________________
 * Returns if the list is empty
 ******************************************************************************/
template<class Type>
bool linkedListType<Type>::isEmptyList()
{
	return(first == NULL);
}

/******************************************************************************
 * Default constructor
 ******************************************************************************/
template<class Type>
linkedListType<Type>::linkedListType() // default constructor
{
	first = NULL;
	last = NULL;
}
/******************************************************************************
 * destroyList
 * ____________________________________________________________________________
 * destroys all nodes in the list
 ******************************************************************************/
template<class Type>
void linkedListType<Type>::destroyList()
{
	nodeType<Type> *temp;   //pointer to deallocate the memory
							//occupied by the node
	while(first != NULL)    //while there are nodes in the list
	{
	   temp = first;        //set temp to the current node
	   first = first->link; //advance first to the next node
	   delete temp;         //deallocate memory occupied by temp
	}
	last = NULL;    //initialize last to NULL; first has already
                   //been set to NULL by the while loop
}

/******************************************************************************
 * print
 * ____________________________________________________________________________
 * prints contents of list
 ******************************************************************************/
template<class Type>
void linkedListType<Type>::print()
{
	if(first == NULL)
	{
		cout << "The list is empty.\n";
	}
	else
	{
		nodeType<Type> *current; //pointer to traverse the list

		current = first;   //set current so that it points to
						   //the first node
		while(current != NULL) //while more data to print
		{
		   cout<<current->info<<" ";
		   current = current->link;
		}
	}
}
/******************************************************************************
 * length
 * ____________________________________________________________________________
 * Returns the length of the list
 ******************************************************************************/
template<class Type>
int linkedListType<Type>::length()
{
	int count = 0;
  	nodeType<Type> *current; //pointer to traverse the list

	current = first;

	while (current!= NULL)
      {
	   count++;
	   current = current->link;
	}

 	return count;
}
/******************************************************************************
 * insertLast
 * ____________________________________________________________________________
 * Inserts node into back of list
 ******************************************************************************/
template<class Type>
void linkedListType<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node
    newNode->info = newItem;      //store the new item in the node
    newNode->link = NULL;         //set the link field of new node
								  //to NULL

	if(first == NULL)  //if the list is empty, newNode is
     			    //both the first and last node
	{
		first = newNode;
		last = newNode;
	}
	else     //if the list is not empty, insert newNnode after last
	{
		last->link = newNode; //insert newNode after last
		last = newNode; //make last point to the actual last node
	}
}
/******************************************************************************
 * deleteNode
 * ____________________________________________________________________________
 * deletes node
 ******************************************************************************/
template<class Type>
void linkedListType<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *trailCurrent; //pointer just before current
	bool found;

	if(first == NULL)    //Case 1; list is empty.
		cout<<"Can not delete from an empty list.\n";
	else
	{
		if(first->info == deleteItem) //Case 2
		{
			current = first;
			first = first ->link;
			if(first == NULL)    //list had only one node
				last = NULL;
			delete current;
		}
		else  //search the list for the node with the given info
		{
			found = false;
			trailCurrent = first;   //set trailCurrent to point to
									//the first node
			current = first->link;	//set current to point to the
    								//second node

			while((!found) && (current != NULL))
			{
  				if(current->info != deleteItem)
				{
					trailCurrent = current;
					current = current-> link;
				}
				else
					found = true;
			} // end while

			if(found) //Case 3; if found, delete the node
			{
				trailCurrent->link = current->link;

				if(last == current)			//node to be deleted was
											//the last node
					last = trailCurrent;	//update the value of last
				delete current;				//delete the node from the list
			}
			else
				cout << deleteItem << " is not in the list." <<endl;
		} //end else
	} //end else
}
/******************************************************************************
 * destructor
 ******************************************************************************/
template<class Type>
linkedListType<Type>::~linkedListType() // destructor
{
	nodeType<Type> *temp;

	while(first != NULL)  //while there are nodes left in the list
	{
		temp = first;         //set temp point to the current node
		first = first->link;  //advance first to the next node
		delete temp;          //deallocate memory occupied by temp
	}//end while

	last = NULL; //initialize last to NULL; first is already null
}//end destructor


/******************************************************************************
 * copy constructor
 ******************************************************************************/
template<class Type>
linkedListType<Type>::linkedListType(
            				const linkedListType<Type>& otherList)
{
    nodeType<Type> *newNode; //pointer to create a node
    nodeType<Type> *current; //pointer to traverse the list

    if(otherList.first == NULL) //otherList is empty
    {
		first = NULL;
		last = NULL;
	}
	else
	{
		current = otherList.first;  //current points to the
									//list to be copied

			//copy the first node
		first = new nodeType<Type>;  //create the node
		first->info = current->info; //copy the info
		first->link = NULL;  	     //set the link field of
									 //the node to NULL
		last = first;    		     //make last point to the
									 //first node
		current = current->link;     //make current point to the
									 //next node

			//copy the remaining list
		while(current != NULL)
		{
			newNode = new nodeType<Type>;	//create a node
			newNode->info = current->info;	//copy the info
			newNode->link = NULL;   	    //set the link of
											//newNode to NULL
			last->link = newNode; 		//attach newNode after last
			last = newNode;   			//make last point to
										//the actual last node
			current = current->link;   //make current point to
										//the next node
		}//end while
	}//end else
}


/******************************************************************************
 * Overload assignment operator
 ******************************************************************************/
template<class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(
   	 	 					const linkedListType<Type>& otherList)
{
	nodeType<Type> *newNode; //pointer to create a node
	nodeType<Type> *current; //pointer to traverse the list.

	if(this != &otherList) //avoid self-copy
	{
		if(first != NULL)  //if the list is not empty, destroy the list
			destroyList();

		if(otherList.first == NULL) //otherList is empty
		{
			first = NULL;
			last = NULL;
		}
		else
		{
			current = otherList.first;	//current points to the
										//list to be copied

				//copy the first element
			first = new nodeType<Type>;		//create the node
   			first->info = current->info;	//copy the info
   			first->link = NULL;  			//set the link field of
											//the node to NULL
			last = first;            //make last point to the first node
			current = current->link; //make current point to the next
  		  							 //node of the list being copied

				//copy the remaining list
			while(current != NULL)
			{
				newNode = new nodeType<Type>;
				newNode->info = current->info;
				newNode->link = NULL;
				last->link = newNode;
				last = newNode;
				current = current->link;
			}//end while
		}//end else
	}//end else

   return *this;
}
/******************************************************************************
 * reverseList
 * ____________________________________________________________________________
 * reverses contents of list
 ******************************************************************************/
template <class Type>
void linkedListType<Type>::reverseList()
{
	  if(first != NULL && first->link != NULL)
	  {
			nodeType<Type>* m = first;
			nodeType<Type>* n = first->link;
			nodeType<Type>* t = NULL;
			if(n->link != NULL)
			{
				t = n->link;
			}
			first->link = NULL;
			while(t->link != NULL)
			{
				n->link = m;
				m = n;
				n = t;
				t = t->link;
			}
			n->link = m;
			first = t;
			t->link = n;
	  }
}
/******************************************************************************
 * insertMiddle
 * ____________________________________________________________________________
 * inserts into middle of list
 ******************************************************************************/
template <class Type>
void linkedListType<Type>::insertMiddle(const Type& newItem)
{
	nodeType<Type> *current;
	nodeType<Type> *newNode;
	newNode = new nodeType<Type>;
	newNode->info = newItem;
	current = first;
	int middle;
	middle = this->length()/2;
	for(int i = 1; i < middle; i ++)
	{
		current = current->link;
	}
	newNode->link = current->link;
	current->link = newNode;

}

#endif /* LINKEDLIST_H_ */
