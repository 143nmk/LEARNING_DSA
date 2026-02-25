/* Cpp code to find the minimum number of coins required for a given amount*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minCoins(vector<int> coins,int amount){
    int n=coins.size();
    int ans=0;

    for(int i=n-1;i>=0 && amount>0;i--){
        if(amount>=coins[i]){
            ans+=amount/coins[i];
            amount=amount%coins[i];
        }

    }
    return ans;
}

int main(){
    vector<int> coins={1,2,5,10,20,50,100,200,500,2000};
    int amount=210;
    cout<<minCoins(coins,amount);
    return 0;

}