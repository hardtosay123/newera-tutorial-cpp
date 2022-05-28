#include <iostream>
#include "Models/CRectangle.h"
using namespace std;

int main() {
    CRectangle r1, r2;
    r1.setValues(3,4);
    r2.setValues(10, 100);
    cout << r1.getArea() << endl;
    cout << r2.getArea() << endl;
    return 0;
}