
#ifndef H_StackType
#define H_StackType
 
#include <iostream>
#include <cassert>

#include "stackADT.h"

using namespace std;

template <class Type>
class stackType: public stackADT<Type>
{
public:
    const stackType<Type>& operator=(const stackType<Type>&); 
      //Overload the assignment operator.

    void initializeStack();
      //Function to initialize the stack to an empty state.

    bool isEmptyStack() const;
      //Function to determine whether the stack is empty.

    bool isFullStack() const;
      //Function to determine whether the stack is full.

    void push(const Type& newItem);
      //Function to add newItem to the stack.

    Type top() const;
      //Function to return the top element of the stack.

    void pop();
      //Function to remove the top element of the stack.

    stackType(int stackSize = 100); 
      //constructor

    stackType(const stackType<Type>& otherStack); 
      //copy constructor

    ~stackType(); 
      //destructor

private:
    int maxStackSize;
    int stackTop;
    Type *list;       

    void copyStack(const stackType<Type>& otherStack); 

};


template <class Type>
void stackType<Type>::initializeStack()
{
    stackTop = 0;
}

template <class Type>
bool stackType<Type>::isEmptyStack() const
{
    return(stackTop == 0);
}

template <class Type>
bool stackType<Type>::isFullStack() const
{
    return(stackTop == maxStackSize);
} 

template <class Type>
void stackType<Type>::push(const Type& newItem)
{
    if (!isFullStack())
    {
        list[stackTop] = newItem; 

        stackTop++;
    }
    else
        cout << "Cannot add to a full stack." << endl;
}

template <class Type>
Type stackType<Type>::top() const
{
    assert(stackTop != 0);   

    return list[stackTop - 1];
}

template <class Type>
void stackType<Type>::pop()
{
    if (!isEmptyStack())
        stackTop--;      
    else
        cout << "Cannot remove from an empty stack." << endl;
}

template <class Type>
stackType<Type>::stackType(int stackSize) 
{
    if (stackSize <= 0)
    {
        cout << "Size of the array to hold the stack must "
             << "be positive." << endl;
        cout << "Creating an array of size 100." << endl;

        maxStackSize = 100;
    }
    else
        maxStackSize = stackSize;   

    stackTop = 0;               
    list = new Type[maxStackSize];  
                        
}

template <class Type>
stackType<Type>::~stackType() 
{
    delete [] list; 
}

template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{ 
    delete [] list;				   
    maxStackSize = otherStack.maxStackSize;		   
    stackTop = otherStack.stackTop;			   
	  
    list = new Type[maxStackSize];		   			   

    for (int j = 0; j < stackTop; j++)  
        list[j] = otherStack.list[j];
} 


template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
    list = NULL;

    copyStack(otherStack);
}

template <class Type>
const stackType<Type>& stackType<Type>::operator= 	(const stackType<Type>& otherStack)
{ 
    if (this != &otherStack) 
        copyStack(otherStack);

    return *this; 
}


#endif