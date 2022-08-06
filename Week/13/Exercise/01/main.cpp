#include <iostream>
#include "../../linkedQueue.h"

using namespace std;

int main()
{
    linkedQueueType<int> queue;
    queue.addQueue(5);
    queue.addQueue(11);
    queue.addQueue(34);
    queue.addQueue(67);
    queue.addQueue(43);
    queue.addQueue(55);
    queue.moveNthFront(3);
    cout << "Queue Elements: ";
    while (!queue.isEmptyQueue()) {
        cout << queue.front() << " ";
        queue.deleteQueue();
    }
    cout << endl;

    return 0;
}