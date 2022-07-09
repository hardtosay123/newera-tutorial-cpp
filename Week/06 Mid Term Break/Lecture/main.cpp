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
    //list1.deleteKthElement(54);
    //list1.print();

    linkedListIterator<int> itr;
    int count = 0;
    for (itr = list1.begin(); itr != list1.end(); ++itr) {
        cout << *itr << endl;
        count++;
    }
    list1.reversePrint();
    /*
    unorderedLinkedList<int> current;
    int last = count;
    current = list1;
    if (!current.isEmptyList()) {
        for (int i = count; i >= 0; i--) {
            linkedListIterator<int> itr1;
            int x = 0;
            for (itr1 = current.begin(); itr1 != current.end(); ++itr1) {
                if (i == x)
                {
                    cout << *itr1 << endl;
                }
                x++;
            }
        }
    }
    */

    return 0;
}