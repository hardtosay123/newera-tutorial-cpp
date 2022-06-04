#include <iostream>

using namespace std;
int mystery(int);
int factorial(int);
int exponential(int, int);
int main()
{
    cout << mystery(5) << endl;
    cout << mystery(4) << endl;
    cout << mystery(3) << endl;
    cout << mystery(2) << endl;
    cout << mystery(1) << endl;
    cout << factorial(60) << endl;
    cout << exponential(5, 4) << endl;
}
int mystery(int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return n + mystery(n-1);
    }
}
int factorial(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return n * mystery(n-1);
    }
}
int exponential(int x, int y) {
    if (y == 0) {
        return 1;
    }
    else {
        return x * exponential(x, y-1);
    }
}