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

bool findPath(Node *root, int n, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if (root->data == n)
    {
        return true;
    }
    bool isLeft = findPath(root->left, n, path);
    bool isRight = findPath(root->right, n, path);
    if (isLeft || isRight)
    {
        return true;
    }
    path.pop_back();
    return false;
}

int LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return -1;
    }
    vector<int> path1;
    vector<int> path2;
    int lca = -1;
    findPath(root, n1, path1);
    findPath(root, n2, path2);
    for (int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++)
    {
        if (path1[i] != path2[j])
        {
            return lca;
        }
        lca = path1[i];
    }
    return lca;
}

int main()
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(preorder);
    int n1 = 4, n2 = 6;
    cout << LCA(root, n1, n2);
    return 0;
}