#include <iostream>

using namespace std;
struct nodeType
{
    int info;
    nodeType *link;
};

nodeType *buildListForward();
nodeType *buildListBackward();
void displayList(nodeType *head = NULL);

nodeType *headForward, *headBackward;

int main()
{
    headForward = buildListForward();

    displayList(headForward);

    headBackward = buildListBackward();

    displayList(headBackward);

    return 0;
}

nodeType *buildListForward()
{
    nodeType *first, *newNode, *last;
    int num;

    cout << "Enter a list of integers ending with -999." << endl;
    cin >> num;
    first = NULL;

    while (num != -999) {
        newNode = new nodeType;
        newNode->info = num;
        newNode->link = NULL;

        if (first == NULL) {
            first = newNode;
            last = newNode;
        }
        else {
            last->link = newNode;
            last = newNode;
        }
        cin >> num;
    }
    return first;
}

nodeType *buildListBackward()
{
    nodeType *first, *newNode;
    int num;

    cout << "Enter a list of integers ending with -999." << endl;
    cin >> num;
    first = NULL;

    while (num != -999) {
        newNode = new nodeType;
        newNode->info = num;
        newNode->link = first;

        first = newNode;
        cin >> num;
    }
    return first;
}

void displayList(nodeType *head) {
    nodeType *current;
    current = head;
    while (current != NULL) {
        cout << current->info << endl;
        current = current->link;
    }
}

//A = A->link;
//list = list->link->link->link;
//B = B->link->link;
//list = NULL;
//B->link->info = 35;