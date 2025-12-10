/* Cpp code to check whether a person is eligible to vote or not using simple if- else statement */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int age;
    cout << "Enter your age:";
    cin >> age;
    if (age >= 18)
    {
        cout << "You are eligible to vote"<<endl;
    }
    else
    {
        cout << "You are not eligible to vote"<<endl;
    }
    return 0;
}