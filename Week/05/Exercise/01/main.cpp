#include <iostream>

using namespace std;
struct classinfo
{
    int stud_id;
    float test, assignment, quiz, final;
    classinfo *next;
};

void newrecord();

classinfo *studentInfo;
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
        cout << "Enter selection:";
        cin >> choice;
        switch (choice) {
            case 1:
                newrecord();
                break;
            case 2:
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
        if (id == current->stud_id) {
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
        
    }
}