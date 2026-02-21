/*Cpp code to evaluate duplciate parenthesis*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isDuplciate(string str)
{
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (ch != ')')
        {
            s.push(ch);
        }
        else
        {
            if (s.top() == '(')
            {
                return true;
            }
            while (s.top() != '(')
            {
                s.pop();
            }
            s.pop();
        }
    }
    return false;
}

int main()
{
    string str = "(x+y)";
    cout << isDuplciate(str) << endl;
    return 0;
}
