#include <iostream>
#include <iomanip>
using namespace std;

const double inchesToCentimeter = 2.54;

void convert(double*);

int main()
{
    double measurement;
    cout << "Enter a length in inches, and I will convert\n";
    cout << "it to centimeters: ";
    cin >> measurement;
    convert(&measurement);
    cout << fixed << setprecision(4);
    cout << "Value in centimeters: " << measurement << endl;
    return 0;
}
void convert(double* measurement)
{
    *measurement *= inchesToCentimeter;
}