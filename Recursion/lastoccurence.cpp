/* Cpp code to return the index of the last occurence of the number in the given array*/

#include <iostream>
#include <vector>
using namespace std;

int lastOccurence(vector<int> &v, int i, int number)
{
    if (i == v.size())
    {
        return -1;
    }
    int index = lastOccurence(v, i + 1, number);
    if (index == -1 && v[i] == number)
    {
        return i;
    }
    return index;
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
    cout << "Enter the number:";
    cin >> number;
    cout << "The index of the last occurence of the number is :" << lastOccurence(v, 0, number) << endl;
    return 0;
}
