/* Cpp code to reverse a number 
 input: N;
 output: reverse of N;

*/

#include<iostream>
using namespace std;


int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    int reverse=0;
    while(n){
    int digit=n%10;
    reverse=reverse*10+digit;
    n=n/10;
    }
    cout<<"Reversed Number is:"<<reverse;
    return 0;
}