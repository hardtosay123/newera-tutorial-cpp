#include <iostream>

using namespace std;

struct item {
    int id;
    string title;
    float price;
    item *next;
};

void Menu();
void newRecord();
//Read the input from user and link new node to existing linked list.

void deleteRecord();
//Ask user to enter input of id. If the value is exists, delete the record. Otherwise, display �No record in database�

void viewRecords();
//Display all records information in the list

item *item_list, *last;
int main()
{
    int choice = 0;
    while (choice != 4) {
        Menu();
        cin >> choice;
        switch (choice)
        {
            case 1:
                newRecord();
                break;
            case 2:
                deleteRecord();
                break;
            case 3:
                viewRecords();
                break;
            case 4:
                cout << "Thank You." << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}

void Menu() {
    cout << "---------------------------------------------------" << endl;
    cout << "                   :: Menu ::                      " << endl;
    cout << "1. Add new record" << endl;
    cout << "2. Delete record" << endl;
    cout << "3. Display records" << endl;
    cout << "4. Exit program" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Enter selection : ";
}

void newRecord() {
    int item_id;
    string title;
    float price;

    cout << "Enter Item ID No : ";
    cin >> item_id;
    cout << "Enter Item Title : ";
    cin >> title;
    cout << "Enter Item price : ";
    cin >> price;

    item* newItem;
    newItem = new item;
    newItem->id = item_id;
    newItem->title = title;
    newItem->price = price;
    newItem->next = NULL;

    if (item_list == NULL)
    {
        item_list = newItem;
        last = item_list;
    }
    else
    {
        last->next = newItem;
        last = newItem;
    }
}

void deleteRecord() {
    int id;
    cout << "Enter Item ID no to delete: ";
    cin >> id;
    cout << "Status : ";

    bool isExist = false;
    item *current, *deletedItem;
    current = item_list;
    if (current != NULL && current->id == id) {
        isExist = true;
        if (current->next == NULL) {
            item_list = NULL;
            last = item_list;
        }
        else {
            item_list = item_list->next;
        }
        delete current;
    }
    else {
        while (current != NULL)
        {
            if (current->next != NULL && current->next->id == id) {
                isExist = true;
                deletedItem = current->next;
                current->next = current->next->next;
                if (current->next == NULL)
                {
                    last = current;
                }
                delete deletedItem;
            }
            current = current->next;
        }
    }
    if (isExist) {
        cout << "Item ID no " << id << " is deleted." << endl;
    }
    else {
        cout << "No record in database" << endl;
    }
}

void viewRecords() {
    int i = 1;
    item *current;
    current = item_list;
    if (current == NULL)
    {
        cout << "No records" << endl;
    }
    else
    {
        while (current != NULL)
        {
            cout << endl;
            cout << "Record " << i << ": " << endl;
            cout << "Item ID No : " << current->id << endl;
            cout << "Item Title : " << current->title << endl;
            cout << "Item Price : " << current->price << endl;
            cout << endl;
            current = current->next;
            i++;
        }
        cout << "End of record" << endl;
    }
}