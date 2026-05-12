/* Cpp code to calculate power of a number */

#include <iostream>
using namespace std;

int main()
{
    double base;
    int exponent;
    double answer = 1;
    cout << "Enter the base value: ";
    cin >> base;
    cout << "Enter the exponent value: ";
    cin >> exponent;
    int m = exponent;
    exponent = abs(exponent);
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            answer *= base;
            exponent--;
        }
        else
        {
            base = base * base;
            exponent = exponent / 2;
        }
    }
    if (m < 0)
    {
        answer = 1.0 / answer;
    }
    cout << "The answer is: " << answer << endl;
    return 0;
}