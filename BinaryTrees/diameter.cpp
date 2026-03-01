/* Cpp code to calculate the diameter of a binary tree*/

#include <iostream>
#include <vector>
#include <algorithm>
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
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int dimater1(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int h = height(root->left) + height(root->right) + 1;
    int ld = dimater1(root->left);
    int rd = dimater1(root->right);
    return max(h, max(ld, rd));
}

pair<int, int> diameter2(Node *root)
{
    if (root == NULL)
    {
        return make_pair(0, 0);
    }
    pair<int, int> left = diameter2(root->left);
    pair<int, int> right = diameter2(root->right);
    int h = max(left.first, right.first) + 1;
    int d = max(left.first + right.first + 1, max(left.second, right.second));
    return make_pair(h, d);
}

int main()
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(preorder);
    cout << "Diameter of the binary tree is: " << dimater1(root) << endl;
    cout << "Diameter of the binary tree is: " << diameter2(root).second << endl;
    return 0;
}