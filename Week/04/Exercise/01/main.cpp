#include <iostream>

using namespace std;

bool isPrime(int, int i = 2);
bool isItAPrimeNumber(int, int);

int main()
{
    /*
    cout << "This will find is the number a prime number." << endl;
    cout << "Please key in your number :" << endl;
    int number;
    cin >> number;
    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    }
    else {
        cout << number << " is not a prime number." << endl;
    }
    */
    cout << "These are prime numbers :" << endl;
    for (int i = 1; i < 101; i++) {
        if (isPrime(i)) {
            cout << i << endl;
        }
    }
}

bool isPrime(int n, int i)
{
    if (n <= 2) {
        return (n == 2);
    }
    if (n % i == 0) {
        return false;
    }
    if (i * i > n) {
        return true;
    }

    return isPrime(n, i + 1);
}
/*
bool isItAPrimeNumber(int n, int x)
{
    if (x == 1) {
        return true;
    }
    else if ((n % x) == 0) {
        return false;
    }
    else {
        return isItAPrimeNumber(n, x - 1);
    }
}
*/