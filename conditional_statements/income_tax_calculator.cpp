// Cpp code to calculate the income tax based on the salary of the user
/*
  income<5L tax=0%
  income<10L tax=20%
  income>10 tax=30%
*/

#include <iostream>
using namespace std;

int main()
{
    float income;
    float tax = 0;
    cout << "Enter your salary(in lakhs): ";
    cin >> income;
    if (income < 5)
    {
        tax = 0 * income;
    }
    else if (income < 10)
    {
        tax = 0.2 * income;
    }
    else
    {
        tax = 0.3 * income;
    }
    cout << "Your tax is: " << tax << " lakhs" << endl;
    cout << "Thank you for using the income tax calculator!" << endl;
    return 0;
}