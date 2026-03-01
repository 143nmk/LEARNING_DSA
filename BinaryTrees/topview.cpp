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

void topview(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<pair<Node *, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int hd = it.second;
        if (m.find(hd) == m.end())
        {
            m[hd] = node->data;
        }
        if (node->left)
        {
            q.push({node->left, hd - 1});
        }
        if (node->right)
        {
            q.push({node->right, hd + 1});
        }
    }
    for (auto it : m)
    {
        cout << it.second << " ";
    }
}

int main()
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(preorder);
    topview(root);
    return 0;
}