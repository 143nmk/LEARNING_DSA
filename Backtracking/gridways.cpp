/* Cpp code to find the number of ways to reach from one corner to other diagonal corner in a gid world*/

#include <iostream>
#include <vector>
using namespace std;

int gridways(int n, int m, int row, int col,string res)
{
    if (row == n - 1 && col == m - 1)
    {
        cout<<res<<"\n";
        return 1;
    }
    if (row == n || col == m)
    {
        return 0;
    }
    int downways = gridways(n, m, row + 1, col,res+"D");
    int rightways = gridways(n, m, row, col + 1,res+"R");
    return downways + rightways;
}

int main()
{
    int n, m;
    cout << "Enter the number of rows and columns" << endl;
    cin >> n >> m;
    int count = gridways(n, m, 0, 0,"");
    cout << "The number of ways to reach the destination is " << count << endl;
    return 0;
}