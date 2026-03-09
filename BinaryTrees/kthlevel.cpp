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
void kthhelper(Node *root, int k, int l)
{
    if (root == NULL)
    {
        return;
    }
    if (k == l)
    {
        cout << root->data << " ";
    }
    kthhelper(root->left, k, l + 1);
    kthhelper(root->right, k, l + 1);
}

void kthlevel(Node *root, int k)
{
    kthhelper(root, k, 1);
    cout << endl;
    return;
}

int main()
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(preorder);
    kthlevel(root, 3);
    return 0;
}