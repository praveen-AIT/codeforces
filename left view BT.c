// Recursive C program for level order traversal of Binary Tree
#include <stdio.h>
#include <stdlib.h>
 
typedef struct node
{
    int data;
    struct node* left, *right;
}node;
 

int height(node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        if (lheight > rheight)
            return(lheight+1);

        else return(rheight+1);
    }
}
 
node* newNode(int data)
{
    node* node = (struct node*)malloc(sizeof(node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return(node);
}

void left_view(node *root, int h, int *max_height)
{
    if(h < 0)
        return;
    if(root !=NULL)
    {
        if(h > *max_height)
        {
            printf("%d\t", root->data);
            *max_height = h;
        }

        left_view(root->left, h+1, max_height);
        left_view(root->right, h+1, max_height);
    }
}

int main()
{
    node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
    root->right->right->right = newNode(80);
 
    int max_height=0;
    left_view(root, 1, &max_height);
    printf("\n"); 
    return 0;
}
