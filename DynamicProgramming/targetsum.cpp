#include<bits/stdc++.h>
using namespace std;

int targetSum(vector<int> &nums,int target){
    int n=nums.size();
    vector<vector<bool>> dp(n+1,vector<bool>(target+1,0));
    dp[0][0]=true;
    for(int i=1;i<n+1;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<target+1;j++){
            if(nums[i-1]<=j){
                dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<target+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][target];
}

int main(){
    vector<int> nums={4,2,7,1,3};
    int target=7;
    cout<<targetSum(nums,target)<<endl;
    return 0;

}