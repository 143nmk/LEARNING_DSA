/* Cpp code to check if a  number is armstrong or not*/

#include <bits/stdc++.h>
using namespace std;

int countDigits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n = n / 10;
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int digits = countDigits(n);
    int temp = n;
    int sum = 0;
    for (int i = 0; i < digits; i++)
    {
        int rem = temp % 10;
        sum += pow(rem, digits);
        temp = temp / 10;
    }
    if (sum == n)
    {
        cout << n << " is an armstrong number." << endl;
    }
    else
    {
        cout << n << " is not an armstrong number." << endl;
    }
}