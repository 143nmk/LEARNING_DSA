/* Cpp code to  compute the ways in which n friends can be paired up*/

#include<iostream>
using namespace std;

int friendsPairing(int n){
    if(n==1 || n==2){
        return n;
    }
    return friendsPairing(n-1)+(n-1)*friendsPairing(n-2);
}

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"The number of ways are: "<<friendsPairing(n)<<endl;

}