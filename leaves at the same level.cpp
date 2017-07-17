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

bool checkUtil(node *root, int level, int *leaflevel)
{
    if(root == NULL)
        return true;

    if(root->left == NULL && root->right == NULL)
    {
        if(*leaflevel == 0)
        {
            *leaflevel = level;
            return true;
        }

        else
            return level == *leaflevel;
    }
    return 
        checkUtil(root->left, level+1, leaflevel) && checkUtil(root->right, 
                     level+1, leaflevel);
}

int check(node *root)
{
    if(root == NULL)
        return 0;

    int leaflevel = 0;
    return checkUtil(root, 0, &leaflevel);    
}

int main()
{
    node *root = newNode(12);
    root->left = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(1);
    
    if (check(root))
        printf("Leaves are at same level\n");
    else
        printf("Leaves are not at same level\n");   

    cout<<endl;
    return 0;
}