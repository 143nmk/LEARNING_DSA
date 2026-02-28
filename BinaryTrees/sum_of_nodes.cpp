#include <iostream>
#include <vector>
#include <queue>
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
static int index = -1;

Node *buildTree(vector<int> preorder)
{
    index++;
    if (preorder[index] == -1)
    {
        return NULL;
    }
    Node *root = new Node(preorder[index]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

int sum_of_nodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSum = sum_of_nodes(root->left);
    int rightSum = sum_of_nodes(root->right);
    return leftSum + rightSum + root->data;
}

int main()
{
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(preorder);
    cout << "Sum: ";
    cout << sum_of_nodes(root) << endl;
    return 0;
}