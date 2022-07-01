#ifndef H_orderedListType
#define H_orderedListType
 
#include "linkedList.h"

using namespace std;

template <class Type>
class orderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const; 
      //Function to determine whether searchItem is in the list.

    void insert(const Type& newItem);
      //Function to insert newItem in the list.

    void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.

    void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
};


#endif

template<class Type>
inline bool orderedLinkedList<Type>::search(const Type & searchItem) const
{
	nodeType<Type> *current; //pointer to traverse the list
	bool found = false;

	current = this->first; //set current to point to the this->first 
						   //node in the list

	while (current != NULL && !found)    //search the list
		if (current->info >= searchItem) //searchItem is found
			found = true;
		else
			current = current->link; //make current point to
									 //the next node

	if (found)
		found = (current->info== searchItem);

	return found;
}

template<class Type>
inline void orderedLinkedList<Type>::insert(const Type & newItem)
{
	nodeType<Type> *current;
	nodeType<Type> *trailcurrent = NULL;
	nodeType<Type> *newNode;
	bool found;

	newNode = new nodeType<Type>; //create the new node
	newNode->info = newItem;  //store the new item in the node
	newNode->link = NULL;

	if (this->first == NULL)  //if the list is empty, newNode is 
							  //both the this->first and this->last node
	{
		this->first = newNode;
		this->last = newNode;
		this->count++;        //increment this->count
	}
	else {
		found = false;
		current = this->first; //set current to point to 
									 //the second node

		while (current != NULL && !found)
		{
			if (current->info >= newItem)
			{
				found = true;
			}
			else {
				trailcurrent = current;
				current = current->link;
			}

		}//end while

		if (current == this->first) {
			newNode->link = this->first;
			this->first = newNode;
			this->count++;
		}
		else {
			trailcurrent->link = newNode;
			newNode->link = current;
			if (current == NULL)
				this->last = newNode;

			this->count++;
		}
	}
}

template<class Type>
inline void orderedLinkedList<Type>::insertFirst(const Type & newItem)
{
	insert(newItem);
}

template<class Type>
inline void orderedLinkedList<Type>::insertLast(const Type & newItem)
{
	insert(newItem);
}

template<class Type>
inline void orderedLinkedList<Type>::deleteNode(const Type & deleteItem)
{
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *trailCurrent = NULL; //pointer just before current
	bool found;

	if (this->first == NULL)    //Case 1; the list is empty. 
		cout << "Cannot delete from an empty list."
		<< endl;
	else
	{
		found = false;
		current = this->first->link; //set current to point to 
									 //the second node

		while (current != NULL && !found)
		{
			if (current->info >= deleteItem)
			{
				found = true;
			}
			else {
				trailCurrent = current;
				current = current->link;
			}
				
		}//end while
		
		if (current ==NULL)
			cout << "The item to be deleted is not in " << "the list." << endl;
		else
			if (current->info == deleteItem) {
				if (this->first == current) {
					this->first = this->first->link;
					if (this->first == NULL)
						this->last = NULL;
					delete current;
				}
				else {
					trailCurrent->link = current->link;
					if (current == this->last)
						this->last = trailCurrent;
					delete current;
				}
				this->count--;
			}
			else
				cout << "The item to be deleted is not in " << "the list." << endl;			
		
	}//end else
}
