#include <iostream>

using namespace std;
struct classinfo
{
    int stud_id;
    float test, assignment, quiz, final;
    classinfo *next;
};

void newrecord();
//to read input from user
//Error message for duplicate student ID : “Error: Duplicate student ID”
void deleterecord();
//deletion based on student ID entered by user
//If record is empty, display “No record in the list”
//void displayrecord();
//to display all records in the list
//If record is empty, display “No record in the list”
//void BestStudent();
//to traverse and display details of student with highest total mark

classinfo *studentInfo, *first, *last;

int main()
{
    int choice = 0;
    do {
        cout << ":: STUDENT RECORD PROGRAM ::" << endl;
        cout << "1. Add new record" << endl;
        cout << "2. Delete record" << endl;
        cout << "3. Display record" << endl;
        cout << "4. Display Best Student" << endl;
        cout << "5. Quit program" << endl;
        cout << "Enter selection :";
        cin >> choice;
        switch (choice) {
            case 1:
                newrecord();
                break;
            case 2:
                deleterecord();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
        }

    } while (choice != 5);
    
    return 0;
}

void newrecord() {
    int id;
    float test, assignment, quiz, final;

    cout << "Enter student ID :";
    cin >> id;

    bool isExist = false;
    classinfo *current;
    current = studentInfo;
    while (current != NULL) {
        if (current->stud_id == id) {
            isExist = true;
        }
        current = current->next;
    }
    if (isExist) {
        cout << "Error: Duplicate student ID" << endl;
    }
    else {
        cout << "Enter midterm test mark [20m] :";
        cin >> test;
        cout << "Enter assignment mark [20m] :";
        cin >> assignment;
        cout << "Enter quiz mark [10m] :";
        cin >> quiz;
        cout << "Enter final exam mark [50m] :";
        cin >> final;
        classinfo *newStudent;
        newStudent = new classinfo;
        newStudent->stud_id = id;
        newStudent->test = test;
        newStudent->assignment = assignment;
        newStudent->quiz = quiz;
        newStudent->final = final;
        newStudent->next = NULL;
        if (studentInfo == NULL) {
            studentInfo = newStudent;
            first = studentInfo;
            last = studentInfo;
        }
        else {
            last->next = newStudent;
            last = newStudent;
        }
    }
}

void deleterecord() {
    int id;
    cout << "Enter id to delete a student record :";
    cin >> id;
    classinfo *current, *prevNode;
    bool isExist = false;
    current = studentInfo;
    if (current != NULL && current->stud_id == id) {
        current = current->next;
        isExist = true;
    }
    else {
        while (current != NULL) {
            prevNode = current;
            current = current->next;
            if (current != NULL && current->stud_id == id) {
                prevNode = prevNode->next->next;
                isExist = true;
                break;
            }
        }
    }
    if (!isExist) {
        cout << "No record in the list" << endl;
    }
}