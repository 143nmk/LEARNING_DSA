/*
  Cpp code to print the largest of three numbers using if-else_if ladder statements.
  input: Three integers from the user.
  output: The largest of the three integers.
*/

#include <iostream>
using namespace std;

int main()
{
   int a, b, c;
   cout << "Enter the three numbers(separated by spaces):";
   cin >> a >> b >> c;
   if (a > b)
   {
      if (a > c)
      {
         cout << a << " is the largest number." << endl;
      }  
   }
   if (b > c)
   {
      cout << b << " is the largest number." << endl;
   }else
      {
         cout << c << " is the largest number." << endl;
      }

   return 0;
}