/* Cpp code to calculate and print the sum of first n natural numebrs using loops
 input: N
 output: sum of first N natural numbers
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    long long sum = 0;
    cout << "Enter a number:";
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }
    cout << "The sum of first " << n << " natural numbers(using loops) is:" << sum << endl;
    cout << "The sum of first " << n << " natural numbers(using formula) is:" << (n * (n + 1)) / 2 << endl;
    return 0;
}