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

void printarray(int path[], int len)
{
    for(int i=0; i<len; i++)
        printf("%d\t", path[i]);
    printf("\n");
}

void printpath(node *root, int path[], int len)
{
    if(root == NULL)
        return;

    path[len++] = root->data;

    if(root->left == NULL && root->right == NULL)
        printarray(path, len);

    else
    {
        printpath(root->left, path, len);
        printpath(root->right, path, len);
    }
}

int main()
{
    node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->right->left = newNode(7);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(5);
 
    int path[1000];
    printpath(root, path, 0);
    printf("\n"); 
    return 0;
}
