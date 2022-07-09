#include <iostream>
#include "myStack.h"

using namespace std;

int main()
{
    double higherGPA = 0.00;
    stackType<string> studentName;
    stackType<string> copyStack;
    int choice = 0;

    string name;
    double gpa = 0.00;
    do {
        cout << "##########################################################" << endl;
        cout << "Please select : " << endl;
        cout << "1. Insert Students Grade" << endl;
        cout << "2. Show Higher GPA Students" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter Student Name: ";
                cin >> name;

                cout << "Enter Student's GPA: ";
                cin >> gpa;

                if (gpa > higherGPA) {
                    higherGPA = gpa;
                    studentName.initializeStack();
                    studentName.push(name);
                }
                else if (gpa == higherGPA) {
                    studentName.push(name);
                }
                break;
            case 2:
                cout << "Higher GPA (" << higherGPA << ") for students : " << endl;
                copyStack = studentName;
                int count = 1;
                while (!copyStack.isEmptyStack()) {
                    cout << count << ". " << copyStack.top() << endl;
                    count++;
                    copyStack.pop();
                }
                break;
        }
    } while (choice != 0);
    
    return 0;
}