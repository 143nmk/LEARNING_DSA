/* Cpp code to print all the digits in a number*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number:";
    cin >> n;
    int temp = n;
    cout << "The digits are:" << endl;
    while (temp > 0)
    {
        cout << temp % 10 << " ";
        temp = temp / 10;
    }
    return 0;
}