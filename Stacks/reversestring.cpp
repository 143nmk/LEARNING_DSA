/* Cpp code to revrse a string using stack */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

string reverseString(string str)
{
    stack<char> s;
    string ans;

    for (char c : str)
    {
        s.push(c);
    }

    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    return ans;
}

int main()
{
    string s;
    getline(cin, s);
    cout << reverseString(s) << endl;
    return 0;
}