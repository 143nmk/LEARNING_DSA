/* Cpp code to calculate and print the sum of odd digits of a number 

  input: n;
  output: sum of odd digits of n;

*/

#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    int sum=0;
    int num=n;
    while(n){
        int digit =n%10;
        if(digit%2!=0){
            sum+=digit;
        }
        n=n/10;
    }
    cout<<"Sum of odd digits in "<<num<<" is:"<<sum<<endl;
    return 0;
}