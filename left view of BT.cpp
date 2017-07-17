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

void printLevel(node *root, int level, int *done)
{
    if(root == NULL)
        return;

    if(level == 1 && (*done == 0))
    {
        printf("%d\n", root->data);
        *done = 1;
        return;
    }
    else
    {
        printLevel(root->left, level-1, done);
        printLevel(root->right, level-1, done);
    }
}

void leftView(node *root)
{
    int levels = height(root);

    for(int i=1; i<=levels; i++)
    {
        int done = 0;
        printLevel(root, i, &done);
    }
}

int main()
{
    node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
    root->right->right->right = newNode(50);
 
    leftView(root);  

    cout<<endl;
    return 0;
}