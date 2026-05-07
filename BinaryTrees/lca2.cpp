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
static int i = -1;

Node *buildTree(vector<int> preorder)
{
    i++;
    if (preorder[i] == -1)
    {
        return NULL;
    }
    Node *root = new Node(preorder[i]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

Node *LCA2(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node *left = LCA2(root->left, n1, n2);
    Node *right = LCA2(root->right, n1, n2);
    if (left != NULL && right != NULL)
    {
        return root;
    }
    return left == NULL ? right : left;
}

int main()
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(preorder);
    int n1 = 3, n2 = 6;
    cout << LCA2(root, n1, n2)->data;
    return 0;
}