// Recursive C program for level order traversal of Binary Tree
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

int sumproperty(node *node)
{
    int ans=0;
    if(node == NULL || node->left == NULL && node->right == NULL)
        return 1;

    else
    {
        int l=0, r=0;

        if(node->left != NULL)
            l = node->left->data;

        if(node->right != NULL)
            r = node->right->data;

        if(node->data == l + r)
            ans = 1;
        
        ans += sumproperty(node->left) + sumproperty(node->right);
    }
    return ans;
}

int main()
{
    node *root  = newNode(10);
    root->left         = newNode(8);
    root->right        = newNode(2);
    root->left->left   = newNode(3);
    root->left->right  = newNode(5);
    root->right->right = newNode(2);
 
    printf("%d\n", sumproperty(root));
    printf("\n"); 
    return 0;
}
