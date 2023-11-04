#include <iostream>
#include <stdlib.h>
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
    struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
    temp->data = val;
    temp->left = temp->right = NULL;
    if (node == NULL)
    {
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
}
bool childrenSumParent(struct tree *node)
{
    if (node == NULL || (node->left == NULL && node->right == NULL))
    {
        return true;
    }
    int sum = 0;
    if (node->left != NULL)
    {
        sum += node->left->data;
    }
    if (node->right != NULL)
    {
        sum += node->right->data;
    }
    return ((node->data == sum) && childrenSumParent(node->left) && childrenSumParent(node->right));
}
void preorder(struct tree *node)
{
    struct tree *root = node;
    if (node == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    root = insert(root, 10);
    insert(root, 0);
    insert(root, 10);
    cout<<childrenSumParent(root)<<endl;
    preorder(root);
}