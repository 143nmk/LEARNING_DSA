#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> jobs(n);
    for(int i=0;i<n;i++){
        cin>>jobs[i].first>>jobs[i].second;
    }
    sort(jobs.begin(),jobs.end(),[](pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    });
    int maxDeadline=0;
    for(int i=0;i<n;i++){
        maxDeadline=max(maxDeadline,jobs[i].first);
    }
    vector<int> schedule(maxDeadline+1,-1);
    int count=0,profit=0;
    for(int i=0;i<n;i++){
        for(int j=jobs[i].first;j>0;j--){
            if(schedule[j]==-1){
                schedule[j]=i;
                count++;
                profit+=jobs[i].second;
                break;
            }
        }
    }
    cout<<count<<" "<<profit<<endl;
}