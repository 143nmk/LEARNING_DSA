/* Cpp code to check whether the given string is valid parentheses or not */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool validParentheses(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (st.empty() && (s[i] == '}' || s[i] == ')' || s[i] == ']'))
        {
            return false;
        }
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            st.push(s[i]);

        else
        {
            char c = st.top();
            if ((c == '{' && s[i] == '}') || (c == '(' && s[i] == ')') || (c == '[' && s[i] == ']'))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main()
{
    string s = "{[]})";
    cout << "The string is ";
    validParentheses(s) ? cout << "Valid" : cout << "Invalid";
    return 0;
}