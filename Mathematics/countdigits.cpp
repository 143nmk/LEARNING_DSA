/* Cpp code to count the number of digits in a given number */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int number;
    cout << "Enter the number:";
    cin >> number;
    int temp = number;
    int count = 0;
    while (temp > 0)
    {
        count++;
        temp = temp / 10;
    }
    cout << "The number of digits in " << number << " is " << count << endl;
    cout << "Formula based " << floor(log10(number)) + 1 << endl;
    return 0;
}