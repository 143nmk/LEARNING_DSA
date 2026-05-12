/* Cpp code to print all the digits in a number*/

#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number:";
    cin >> n;
    int temp = n;
    int sum = 0;
    while (temp > 0)
    {
        sum += temp % 10;
        temp = temp / 10;
    }
    cout << "The sum of digits is: " << sum << endl;
    return 0;
}