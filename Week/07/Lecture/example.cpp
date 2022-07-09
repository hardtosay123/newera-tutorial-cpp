#include <iostream>
#include "myStack.h"

using namespace std;

int main()
{
    stackType<int> stack;
    int x, y;
    x = 4;
    y = 0;
    stack.push(7);
    stack.push(x);
    stack.push(x + 5);
    y = stack.top();
    stack.pop();
    stack.push(x + y);
    stack.push(y - 2);
    stack.push(3);
    x = stack.top();
    stack.pop();

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    
    while (!stack.isEmptyStack()) {
        cout << stack.top() << endl;
        stack.pop();
    }

    return 0;
}