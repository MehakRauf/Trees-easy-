#include <iostream>
#include <stdlib.h>
using namespace std;

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree *newNode(int value)
{
    struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}
struct tree *arraytoBST(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    struct tree *root = newNode(arr[mid]);

    root->left=arraytoBST(arr,start,mid-1);
    root->right=arraytoBST(arr,mid+1,end);
    return root;
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
    int arr[]={1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    struct tree *root=arraytoBST(arr,0,n-1);
    preorder(root);
}