/* Cpp code to calculate and print the sum of digits of a number
    input: number n;
    output: sum of digits of n

*/

#include <iostream>
using namespace std;

int main(){
    int n;
    int sum=0;
    cout<<"Enter a number:";
    cin>>n;
    while(n>0){
        sum+=n%10;
        n=n/10;
    }
    cout<<"Sum of digits is:"<<sum<<endl;
    return 0;
    }