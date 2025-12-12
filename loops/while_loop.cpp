/* Cpp code to demonstarte the use of while loop 
input: No input required
output: Prints numbers from 1 to 5 

*/

#include <iostream>
using namespace std;

int main()
{
    int i = 1; // Initialization

    // Condition check
    while (i <= 5)
    {
        cout << i << " "; // Print the current value of i
        i++;              // Increment i by 1
    }
    cout<<endl;
    return 0;
}