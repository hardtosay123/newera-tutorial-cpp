#include <iostream>

using namespace std;

int SearchStudent(int *, int);

int arraySize = 0;

int main()
{
    
    cout << "Input total number of student: ";
    cin >> arraySize;
    int studentId[999];
    //int* ptrSize = &arraySize;
    for (int i = 0; i < arraySize; i++)
    {
        int input_id;
        cout << "Student #" << (i + 1) << ": ";
        cin >> studentId[i];
    }

    int search;
    cout << "Search student ID: ";
    cin >> search;
    cout << "Found at index " << SearchStudent(studentId, search) << ".";
    return 0;
}

int SearchStudent(int *studentArray, int Search) {
    int index = -1;
    for (int y = 0; y < arraySize; y++) {
        if (studentArray[y] == Search) {
            index = y;
        }
    }
    return index;
}