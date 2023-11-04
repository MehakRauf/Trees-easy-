#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
    int height;
};

struct tree *root = NULL;

int getHeight(struct tree *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}

int calculateHeight(struct tree *node)
{
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

tree *insert(struct tree *node, int val)
{
    if (node == nullptr)
    {
        struct tree *temp = new struct tree;
        temp->data = val;
        temp->left = nullptr;
        temp->right = nullptr;
        temp->height = 1; // Set height as 1 for newly inserted node
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

    node->height = calculateHeight(node); // Update the height of the current node

    return node;
}

bool heightbalanced(struct tree *node)
{
    if (node == nullptr)
    {
        return true;
    }
    int lh = getHeight(node->left);
    int rh = getHeight(node->right);

    if (abs(lh - rh) <= 1 && heightbalanced(node->left) && heightbalanced(node->right))
    {
        return true;
    }
    return false;
}

void preorder(struct tree *node)
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

int main()
{
    root = insert(root, 3);
    insert(root, 4);
    insert(root, 2);
    insert(root, 5);
    insert(root, 6);

    preorder(root);
    cout << endl;
    cout << heightbalanced(root) << endl;
    return 0;
}