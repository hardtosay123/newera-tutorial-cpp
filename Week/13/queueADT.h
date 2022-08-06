//Header file: stackADT.h

#ifndef H_queueADT
#define H_queueADT
  
template <class Type>
class queueADT
{
public:
    virtual bool isEmptyQueue() const = 0;
      //Function to determine whether the queue is empty.

    virtual bool isFullQueue() const = 0;
      //Function to determine whether the queue is full.

    virtual void initializeQueue() = 0;
      //Function to initialize the queue to an empty state.

    virtual Type front() const = 0;
      //Function to return the first element of the queue. 

    virtual Type back() const = 0;
      //Function to return the last element of the queue.

    virtual void addQueue(const Type& queueElement) = 0;
      //Function to add queueElement to the queue.

    virtual void deleteQueue() = 0;
      //Function to remove the first element of the queue.
};

        
#endif