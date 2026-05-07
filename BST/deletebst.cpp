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
Node *IS(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL || root->right == NULL)
        {
            if (root->left != NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            if (root->right != NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
        }
        else
        {
            Node *is = IS(root->right);
            root->data = is->data;
            root->right = deleteNode(root->right, is->data);
        }
    }
    return root;
}

int main()
{
    vector<int> arr = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node *root = buildBST(arr);
    inorderTraversal(root);
    cout << endl;
    int del = 3;
    root=deleteNode(root, del);
    inorderTraversal(root);
    cout << endl;
    return 0;
}