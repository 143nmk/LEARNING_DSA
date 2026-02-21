/*Cpp code to find the first non-repeating character in a string*/

#include <iostream>
#include <queue>
using namespace std;

void nonRepeatingLetter(string s)
{
    int freq[26] = {0};
    queue<char> q;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        freq[ch - 'a']++;
        q.push(ch);
        while (!q.empty() && freq[q.front() - 'a'] > 1)
        {
            q.pop();
        }
        if (q.empty())
        {
            cout << "-1" << " ";
        }
        else
        {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main()
{
    string s = "aabccxb";
    nonRepeatingLetter(s);
    return 0;
}