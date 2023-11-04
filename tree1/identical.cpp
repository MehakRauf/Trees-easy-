#include <iostream>
using namespace std;

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

tree *newNode(int val)
{
    struct tree *temp = (struct tree*)malloc(sizeof(struct tree));   
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

bool identical(struct tree *t1, struct tree *t2)
{
    if (t1 == NULL && t2 == NULL)
    {
        return true;
    }
    if (t1 == NULL || t2 == NULL)
    {
        return false;
    }
    if (t1->data != t2->data)
    {
        return false;
    }
    return identical(t1->left, t2->left) && identical(t1->right, t2->right);
}

void preorder(struct tree *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

int main()
{
    tree *root1 = newNode(1);
    tree *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);

    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    cout << "Tree 1: ";
    preorder(root1);
    cout << endl;

    cout << "Tree 2: ";
    preorder(root2);
    cout << endl;

    if(identical(root1, root2)){
        cout << "The trees are identical.";
    } else {
        cout << "The trees are not identical.";
    }

    return 0;
}