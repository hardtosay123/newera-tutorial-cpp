#include <iostream>
#include <iomanip>
using namespace std;

double calcAverage(int*, int);
int findLowest(int*, int);

int main()
{
    int subjects;
    cout << "Please provide your total number of subjects in integer: " << endl;
    cin >> subjects;

    int scores[subjects];
    for (int i = 0; i < subjects; i++)
    {
        cout << "Scores for the No. " << (i+1) << "'s subject: ";
        cin >> scores[i];
    }
    cout << "The average score is : " << calcAverage(scores, subjects) << endl;
    cout << "The lowest score is : " << findLowest(scores, subjects) << endl;
    return 0;
}
double calcAverage(int* scores, int subjects)
{
    int total = 0;
    for (int i = 0; i < subjects; i++)
    {
        total += scores[i];
    }
    return (total / (double)(subjects));
}
int findLowest(int* scores, int subjects)
{
    int lowest = scores[0];
    for (int i = 0; i < subjects; i++)
    {
        if (lowest > scores[i])
        {
            lowest = scores[i];
        }
    }
    return lowest;
}