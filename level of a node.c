#include <stdio.h>
#include <bits/stdc++.h>
 
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

int level(node *root, int n, int h)
{
    if(root == NULL)
        return 0;
    if(root != NULL && h == 1)
    {
        if(root->data == n)
            return 1;
        else
            return 0;
    }
    else
    {
        return level(root->left, n, h-1) + level(root->right, n, h-1);
    }
}

int main()
{
    int ans = 0;
    node *root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
 
    for(int i=1; i<=height(root); i++)
    {
        ans = level(root, 4, i);
        if(ans)
            printf("%d\n", i);
    }
    return 0;
}
