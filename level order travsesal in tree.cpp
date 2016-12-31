#include <stdio.h>
#include <stdlib.h>
#include <iostream>
 
using namespace std;
 
typedef struct node
{
    int data;
    struct node *left, *right;
}node;

void printGivenLevel(struct node* root, int level)
{
    if(root == NULL)
        return;
    if(level == 1)
    {
        cout<<root->data<<" ";
    }
    else
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

int height(struct node* root)
{
    if(root == NULL)
        return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    if(lheight > rheight)
        return lheight+1;
    else
        return rheight+1;
}

void printLevelOrder(struct node* root)
{
    int x = height(root);
    for(int i=1; i<=x; i++)
        printGivenLevel(root, i);
}

node *new_node(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main(void)
{
    node *root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->right->right = new_node(5);

    printLevelOrder(root);
    cout<<endl;
    return (0);
}