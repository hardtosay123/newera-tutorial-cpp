#include <iostream>

using namespace std;
struct nodeType
{
    int info;
    nodeType *link;
};

nodeType *head;

int main()
{
    nodeType *node1 = new nodeType;
    node1->info = 17;
    nodeType *node2 = new nodeType;
    node2->info = 92;
    nodeType *node3 = new nodeType;
    node3->info = 63;
    nodeType *node4 = new nodeType;
    node4->info = 45;

    head = node1;
    node1->link = node2;
    node2->link = node3;
    node3->link = node4;
    node4->link = NULL;

    nodeType *newNodeToBeInsert = new nodeType;
    newNodeToBeInsert->info = 5060;
    newNodeToBeInsert->link = node3->link;
    node3->link = newNodeToBeInsert;


    node2->link = node3->link;//node2->link = node2->link->link
    

    nodeType *current;
    current = head;
    int total = 0;
    while (current != NULL) {
        total += current->info;
        cout << current->info << endl;
        current = current->link;
    }

    cout << "The total amount is " << total << endl;
    
    return 0;
}