/* Cpp code to print all subsets of a string using backtracking*/

#include <iostream>
#include <string>
using namespace std;

void printSubsets(string str, string ans)
{
    if (str.size() == 0)
    {
        if (ans.size() == 0)
            cout << "Empty String" << endl;
        else
            cout << ans << endl;
        return;
    }
    char ch = str[0];
    printSubsets(str.substr(1), ans + ch);
    printSubsets(str.substr(1), ans);
}

int main()
{
    string str;
    cout << "Enter a string:";
    cin >> str;
    printSubsets(str, "");
    return 0;
}