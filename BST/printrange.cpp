/* Cpp code to build the bst tree */

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
        this->left = this->right = NULL;
    }
};

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

Node *buildBST(vector<int> &arr)
{
    Node *root = NULL;
    for (int i = 0; i < arr.size(); i++)
    {
        root = insert(root, arr[i]);
    }
    return root;
}
void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void printRange(Node *root, int start, int end)
{
    if (root == NULL)
    {
        return;
    }
    if (start <= root->data && root->data <= end)
    {
        
        printRange(root->left, start, end);
        cout << root->data << " ";
        printRange(root->right, start, end);
    }
    else if (root->data < start)
    {
        printRange(root->right, start, end);
    }
    else
    {
        printRange(root->left, start, end);
    }
}

int main()
{
    vector<int> arr = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node *root = buildBST(arr);
    inorderTraversal(root);
    cout << endl;
    int start = 5, end = 12;
    printRange(root, start, end);
    return 0;
}