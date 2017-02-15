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

int check(node *root, int n, int sum)
{
    int ans=0;

    if(root == NULL)
        return 0;

    else
    {
        sum += root->data;
        
        if(sum == n && root->left == NULL && root->right == NULL)
            return 1;

        ans = check(root->left, n, sum) || check(root->right, n, sum);
    }
    return ans;
}

int main()
{
    node *root = newNode(10);
    root->left        = newNode(8);
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);
 
    printf("%d\n", check(root, 21, 0));
    printf("\n"); 
    return 0;
}
