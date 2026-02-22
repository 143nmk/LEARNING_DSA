/*Cpp code to implement the pairs datat structure*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    //return a.second < b.second;
    //return a.second > b.second;
     return a.first < b.first;
    // return a.first>b.first;
}

int main()
{
    vector<pair<int, int>> p(4, make_pair(0, 0));
    p[0] = make_pair(12, 25);
    p[1] = make_pair(1, 4);
    p[2] = make_pair(21, 58);
    p[3] = make_pair(3, 2);
    sort(p.begin(), p.end(), compare);
    for (int i = 0; i < p.size(); i++)
    {
        cout << p[i].first << " " << p[i].second << endl;
    }
    cout << endl;
    return 0;
}