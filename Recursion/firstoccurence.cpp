/* Cpp code to return the index of the first occurence of given number in the array*/

#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> &v, int i, int number)
{
    if (i == v.size())
        return -1;
    if (v[i] == number)
        return i;
    return firstOccurence(v, i + 1, number);
}

int main()
{
    int n;
    cout << "Enter the size of the array:";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements of the array:";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int number;
    cout << "Enter the target number:";
    cin >> number;
    cout << "The index of the first occurence of the number:" << firstOccurence(v, 0, number) << endl;
    return 0;
}