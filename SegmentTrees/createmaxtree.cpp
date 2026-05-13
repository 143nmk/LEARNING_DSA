/* Cpp code to create a sum segment tree*/

#include<iostream>
#include<vector>
using namespace std;

class SegmentTree{
    vector<int> tree;
    public:
    SegmentTree(vector<int> arr){
        int n=arr.size();
        tree.resize(4*n);
    }

    void buildTree(vector<int> arr,int start,int end,int index){
        if(start==end){
            tree[index]=arr[start];
            return;
        }
        int mid=start+(end-start)/2;
        buildTree(arr,start,mid,2*index+1);
        buildTree(arr,mid+1,end,2*index+2);
        tree[index]=max(tree[2*index+1],tree[2*index+2]);
    }
    void print(){
        for(int i=0;i<tree.size();i++){
            cout<<tree[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    int n;
    vector<int> arr={6,8,-1,2,17,1,3,2,4};
    SegmentTree st(arr);
    st.buildTree(arr,0,arr.size()-1,0);
    st.print();
    return 0;
}