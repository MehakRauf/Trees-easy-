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
    root=insert(root,3);
    insert(root,4);
    insert(root,5);
    insert(root,2);
    insert(root,1);
    insert(root,38);
    insert(root,30);
    preorder(root);

}