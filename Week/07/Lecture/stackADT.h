
#ifndef H_StackADT 
#define H_StackADT
 
template <class Type>
class stackADT
{
public:
    virtual void initializeStack() = 0;
       //Method to initialize the stack to an empty state.

    virtual bool isEmptyStack() const = 0;
      //Function to determine whether the stack is empty.

    virtual bool isFullStack() const = 0;
      //Function to determine whether the stack is full.

    virtual void push(const Type& newItem) = 0;
      //Function to add newItem to the stack.

    virtual Type top() const = 0;
      //Function to return the top element of the stack.

    virtual void pop() = 0;
      //Function to remove the top element of the stack.
};
        
#endif