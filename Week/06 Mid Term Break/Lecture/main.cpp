#include <iostream>
#include "unorderedLinkedList.h"

using namespace std;

int main()
{
    unorderedLinkedList<int> list1;
    list1.insertLast(28);
    list1.insertLast(17);
    list1.insertLast(37);
    list1.insertLast(24);
    list1.insertLast(54);
    //list1.print();
    
    linkedListIterator<int> itr;
    for (itr = list1.begin(); itr != list1.end(); ++itr) {
        cout << *itr << endl;
    }

    return 0;
}