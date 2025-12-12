/* Cpp code to demonstarte the use of do-while loop 
input: No input required
output: Prints numbers from 1 to 5 

*/

#include <iostream>
using namespace std;

int main()
{
    int i = 1; // Initialization    
    // do-while loop
    do
    {
        cout << i << " "; // Print the current value of i
        i++;              // Increment i by 1
    } while (i <= 5);    // Condition check
    cout<<endl;
    return 0;
}
    