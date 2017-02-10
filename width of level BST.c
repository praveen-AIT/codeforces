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

int levelorderUtil(node *root, int h, int *width)
{
    if(root != NULL)
    {
        if(h == 1)
            (*width)++;

        else 
            levelorderUtil(root->left, h-1, width);
            levelorderUtil(root->right, h-1, width);
    }
    return *width;
}

void levelorder(node * root)
{
    int h = height(root);

    for(int i=1; i<=h; i++)
    {
        int width = 0;
        int ans = levelorderUtil(root, i, &width);
        printf("%u\n", ans);
    }
}

int main()
{
    node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);    
    root->right->right->left  = newNode(6);    
    root->right->right->right  = newNode(7);
 
    int m=0;
    levelorder(root);
    printf("\n"); 
    return 0;
}
