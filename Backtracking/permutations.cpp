/*Cpp code to find the permutations of a given string*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void permutation(string str, string ans)
{
    if (str.size() == 0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        string ros = str.substr(0, i) + str.substr(i + 1);
        permutation(ros, ans + ch);
    }
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;
    string str1 = str;
    // Method 1
    //  Sort the string to ensure we start with the smallest lexicographical permutation
    sort(str.begin(), str.end());

    vector<string> permutations;
    do
    {
        permutations.push_back(str);
    } while (next_permutation(str.begin(), str.end()));

    cout << "Permutations of the string are:\n";
    for (const auto &perm : permutations)
    {
        cout << perm << endl;
    }
    // Method 2: Using backtracking
    cout << "\nUsing Backtracking:\n";
    permutation(str1, "");
    return 0;
}