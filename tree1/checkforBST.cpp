#include <iostream>
#include <cstdlib>
using namespace std;

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree *root = NULL;

tree *insert(struct tree *node, int val)
{
    if (node == NULL)
    {
        struct tree *temp = new struct tree;
        temp->data = val;
        temp->left = temp->right = NULL;
        return temp;
    }
    else if (val < node->data)
    {
        node->left = insert(node->left, val);
    }
    else
    {
        node->right = insert(node->right, val);
    }
    return node;
}

bool isBST(struct tree *node, int minValue, int maxValue)
{
    if (node == NULL)
        return true;

    if (node->data < minValue || node->data > maxValue)
        return false;

    return isBST(node->left, minValue, node->data - 1) &&
           isBST(node->right, node->data + 1, maxValue);
}

bool BST(struct tree *node)
{
    return isBST(node,  -2147483648, 2147483647);
}

void preorder(struct tree *node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

int main()
{
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 38);
    root = insert(root, 30);
    preorder(root);
    cout << endl << BST(root) << endl;
}