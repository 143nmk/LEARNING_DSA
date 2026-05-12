/* Cpp code to reverse a number*/

#include <iostream>
using namespace std;

int main()
{
    int num, rev = 0;
    cout << "Enter number:";
    cin >> num;
    bool isNegative = num < 0;

    int temp = num;
    temp = abs(temp);
    while (temp > 0)
    {
        int digit = temp % 10;
        rev = rev * 10 + digit;
        temp = temp / 10;
    }
    rev = isNegative ? -rev : rev;
    cout << "Reverse of " << num << " is " << rev << endl;
    if (num == rev)
    {
        cout << "The number is a palindrome." << endl;
    }
    else
    {
        cout << "The number is not a palindrome." << endl;
    }
    return 0;
}