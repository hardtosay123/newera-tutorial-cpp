
#include <iostream>
#include "linkedQueue.h"

using namespace std;

void registerPatient();
void call();
void displayQueue();
linkedQueueType<int> queueNumberList;
linkedQueueType<string> queueNameList;
linkedQueueType<string> queueIcList;
int main()
{
    int choice = 1;
    do {
        cout << "----------------------------------------------" << endl;
        cout << ":: Queue Management System (QMS) ::" << endl;
        cout << "1. Register new patient" << endl;
        cout << "2. Call patient" << endl;
        cout << "3. Display queue" << endl;
        cout << "0. Exit Program" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Enter selection: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                registerPatient();
                break;
            case 2:
                call();
                break;
            case 3:
                displayQueue();
                break;
            default:
                break;
        }
    } while (choice != 0);
}
void registerPatient() {
    string name = "", ic = "";
    
    cout << "Enter patient name: ";
    cin >> name;
    cout << "Enter patient IC: ";
    cin >> ic;
    int queueNumber;
    if (queueNumberList.isEmptyQueue()) {
        queueNumberList.initializeQueue();
        queueNumber = 1001;
        queueNumberList.addQueue(queueNumber);
    }
    else {
        queueNumber = queueNumberList.back() + 1;
        queueNumberList.addQueue(queueNumber);
    }
    if (queueNameList.isEmptyQueue()) {
        queueNameList.initializeQueue();
    }
    if (queueIcList.isEmptyQueue()) {
        queueIcList.initializeQueue();
    }
    queueNameList.addQueue(name);
    queueIcList.addQueue(ic);
    cout << "Registered successful. Your queue number is " << queueNumber << endl;
}
void call() {
    if (!(queueNumberList.isEmptyQueue() || queueNameList.isEmptyQueue() || queueIcList.isEmptyQueue())) {
        cout << "<< Current queue number: " << queueNumberList.front() << " >>" << endl;
        queueNumberList.deleteQueue();
        queueNameList.deleteQueue();
        queueIcList.deleteQueue();
    }
    else {
        cout << "The queue is empty!" << endl;
    }
}
void displayQueue() {
    //cout << queueNameList.front();
    linkedQueueType<int> tempNumberList;
    linkedQueueType<string> tempNameList;
    linkedQueueType<string> tempIcList;
    if (queueNumberList.isEmptyQueue() || queueNameList.isEmptyQueue() || queueIcList.isEmptyQueue()) {
        cout << "The queue is empty!" << endl;
    }
    else {
        while (!queueNumberList.isEmptyQueue()) {
            cout << "Queue No: " << queueNumberList.front() << endl;
            cout << "Patient Name: " << queueNameList.front() << endl;
            cout << "Patient IC: " << queueIcList.front() << endl;


            tempNumberList.addQueue(queueNumberList.front());
            tempNameList.addQueue(queueNameList.front());
            tempIcList.addQueue(queueIcList.front());
            queueNumberList.deleteQueue();
            queueNameList.deleteQueue();
            queueIcList.deleteQueue();
        }

        queueNumberList.initializeQueue();
        queueNameList.initializeQueue();
        queueIcList.initializeQueue();
        while (!tempNumberList.isEmptyQueue()) {
            queueNumberList.addQueue(tempNumberList.front());
            queueNameList.addQueue(tempNameList.front());
            queueIcList.addQueue(tempIcList.front());
            tempNumberList.deleteQueue();
            tempNameList.deleteQueue();
            tempIcList.deleteQueue();
        }
    }
}