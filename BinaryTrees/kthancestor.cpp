/* Cpp code to build the binary tree from preorder*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

int kthAncestor(Node * root,int node,int k){
    if(root==NULL){
        return -1;
    }
    if(root->data==node){
        return 0;
    }
    int leftDist=kthAncestor(root->left,node,k);
    int rightDist=kthAncestor(root->right,node,k);
    if(leftDist==-1 && rightDist==-1){
        return -1;
    }
    int validval=leftDist==-1?rightDist:leftDist;
    if(validval+1==k){
        cout<<root->data;
    }
    return validval+1;
}

Node *buildTree(vector<int> preorder, int index = 0)
{
    if (preorder[index] == -1)
    {
        return NULL;
    }
    Node *root = new Node(preorder[index]);
    index++;
    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);
    return root;
}

int main()
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(preorder);
    // cout << root->data;
    cout<<kthAncestor(root,6,1);
    return 0;
}