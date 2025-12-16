/*  Cpp code to print the decimal value of a given binary number
input: integer in binary format
output: integer decimal value of the binary number
assumption: input is a valid unsigned binary number
*/

#include <iostream>
using namespace std;

int binaryToDecimal(int);

int main(){
    int n;
    cout<<"Enter the binary numberin the series of 0s and 1s(without spaces): ";
    cin>>n;
    cout<<"The decimal value of binary number "<<n<<" is: "<<binaryToDecimal(n)<<endl;
    return 0;
}

int binaryToDecimal(int n){
    int result=0;
    int pow=1;
    while(n>0){
        int digit=n%10;
        result+=digit*pow;
        pow=pow*2;
        n/=10;
    }
    return result;
}