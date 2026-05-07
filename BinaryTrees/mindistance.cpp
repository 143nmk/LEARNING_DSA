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

int Distance(Node *root, int n)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == n)
    {
        return 0;
    }
    int left = Distance(root->left, n);

    if (left != -1)
    {
        return left + 1;
    }
    int right = Distance(root->right, n);
    if (right != -1)
    {
        return right + 1;
    }
    return -1;
}

int minDistance(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return 0;
    }
    Node *lca = LCA2(root, n1, n2);
    int left = Distance(lca, n1);
    int right = Distance(lca, n2);
    return left + right;
}

int main()
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(preorder);
    int n1 = 3, n2 = 6;
    cout << minDistance(root, n1, n2);
    return 0;
}