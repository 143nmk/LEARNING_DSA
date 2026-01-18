/* Cpp cpode to remove the duplicate characters from String */

#include <iostream>
#include <cstring>
#include <map>
using namespace std;

string removeDuplicatesForward(string s, int i, string ans, bool track[26])
{
    if (i == s.length())
    {
        return ans;
    }
    int index = s[i] - 'a';
    if (!track[index])
    {
        ans += s[i];
        track[index] = true;
    }
    return removeDuplicatesForward(s, i + 1, ans, track);
}

string removeDuplicatesBackward(string s, string ans, bool track[26])
{
    if (s.length() == 0)
    {
        return ans;
    }
    char c = s[s.length() - 1];
    int index = c - 'a';
    s = s.substr(0, s.length() - 1);
    if (!track[index])
    {
        ans += c;
        track[index] = 1;
    }
    return removeDuplicatesBackward(s, ans, track);
}

int main()
{
    string s;
    cout << "Enter the string:";
    cin >> s;
    bool m[26] = {0};
    bool j[26] = {0};
    cout << "The unique string is: " << removeDuplicatesForward(s, 0, "", m) << endl;
    cout << "The unique string is: " << removeDuplicatesBackward(s, "", j) << endl;
}