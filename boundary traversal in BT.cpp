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
 
void printInorder(struct node* node)
{
     if (node == NULL)
          return;
     printInorder(node->left);
     printf("%d ", node->data);
     printInorder(node->right);
}

node* newNode(int data)
{
    node* Node = (node*)malloc(sizeof(node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return(Node);
} 

void displaynode_l(node *root)
{
    if(root == NULL)
        return;

    if(root->left)
    {
        cout<<root->data<<" ";
        displaynode_l(root->left);
    }

    else if(root->right)
    {
        cout<<root->data<<" ";
        displaynode_l(root->right);
    }
}

void displaynode_r(node *root)
{
    if(root == NULL)
        return;

    if(root->right)
    {
        displaynode_r(root->right);
        cout<<root->data<<" ";
    }

    else if(root->left)
    {
        displaynode_r(root->left);
        cout<<root->data<<" ";
    }
}

void displayleaves_l(node *root)
{
    if(root == NULL)
        return;
    else
    {
        displayleaves_l(root->left);

        if(root->left == NULL && root->right == NULL)
            cout<<root->data<<" ";

        displayleaves_l(root->right);
    }
}

void printBoundary(node *root)
{
    if(root == NULL)
        return;

    displaynode_l(root);

    displayleaves_l(root->left);
    displayleaves_l(root->right);

    displaynode_r(root->right);
}

int main()
{
    node *root                = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
 
    printBoundary( root );    

    cout<<endl;
    return 0;
}