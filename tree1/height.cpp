#include <iostream>
#include <cstdlib>
#include <cmath>
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
    if(node == NULL) {
        return 0;
    }
    return node->height;
}

int calculateHeight(struct tree *node)
{
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

tree* insert(struct tree *node, int val)
{
    if (node == NULL)
    {
        struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
        temp->data = val;
        temp->left = temp->right = NULL;
        temp->height = 1;    // Set height as 1 for newly inserted node
        node = temp;
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

    node->height = calculateHeight(node);   // Update the height of the current node

    return node;
}

void preorder(struct tree *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " " << node->height << endl;
    preorder(node->left);
    preorder(node->right);
}

int main()
{
    root = insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 2);
    insert(root, 1);
    insert(root, 38);
    insert(root, 30);
    preorder(root);
    return 0;
}