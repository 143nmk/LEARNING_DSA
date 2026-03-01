/* Cpp code to build the binary tree from preorder*/

#include <bits/stdc++.h>
#include <vector>
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
bool isIdentical(Node *root, Node *subroot)
{
    if (root == NULL && subroot == NULL)
    {
        return true;
    }
    if (root == NULL || subroot == NULL)
    {
        return false;
    }
    if (root->data != subroot->data)
    {
        return false;
    }
    return isIdentical(root->left, subroot->left) && isIdentical(root->right, subroot->right);
}

bool isSubtree(Node *root, Node *subroot)
{
    if (root == NULL && subroot == NULL)
    {
        return true;
    }
    if (root == NULL || subroot == NULL)
    {
        return false;
    }
    if (root->data == subroot->data)
    {
        if (isIdentical(root, subroot))
        {
            return true;
        }
    }
    bool leftans = isSubtree(root->left, subroot);
    if (!leftans)
    {
        return isSubtree(root->right, subroot);
    }
    return true;
}

int main()
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(preorder);
    vector<int> subpreorder = {7, 4, -1, -1, 3, -1, -1};
    Node *subroot = buildTree(subpreorder);
    cout << isSubtree(root, subroot) << endl;
    return 0;
}