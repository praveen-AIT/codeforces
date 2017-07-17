#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h> 

using namespace std;

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;
 
node* newNode(int );

int height(node *root)
{
    if(root == NULL)
        return 0;

    return 1 + max(height(root->right), height(root->left));
} 
 
node* newNode(int data)
{
    node* Node = (node*)malloc(sizeof(node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return(Node);
} 

int diameter(node *root)
{
    if(root == NULL)
        return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);
    int d = lheight + rheight + 1;

    return max(d, max(diameter(root->left), diameter(root->right)));
}

int main()
{
    node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->left->right->right = newNode(6);

    printf("Diameter of the given binary tree is %d\n", diameter(root));
    return 0;
}