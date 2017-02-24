#include <stdio.h>
#include <limits.h>
#include <bits/stdc++.h>
 
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;
 
bool print_maxpath(struct node *root, struct node *target_leaf)
{
    if (root == NULL)
        return false;
 
    if (root == target_leaf || 
        print_maxpath(root->left, target_leaf) ||
        print_maxpath(root->right, target_leaf) )
    {
        printf("%d ", root->data);
        return true;
    }
    return false;
}
 
struct node* newNode (int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int height(node *root)
{
    if(root == NULL)
        return 0;
    
    int lheight = height(root->left);
    int rheight = height(root->right);

    return lheight > rheight ? lheight+1 : rheight+1;
}

int calculate_sum_level(node *root, int level)
{
    if(root == NULL || level == 0)
        return 0;

    if(level == 1)
        return root->data;
    
    else
        return calculate_sum_level(root->right, level-1) + 
               calculate_sum_level(root->left, level-1);
}

int difference(node *root)
{
    int esum=0, osum=0;

    printf("%d\n", h);
    for(int i=1; i<=h; i++)
    {
        if(i%2==0)
            esum += calculate_sum_level(root, i);
        else
            osum += calculate_sum_level(root, i);
    }
    return esum - osum;
}

int main()
{
    node *root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left  = newNode(1);
    root->left->right = newNode(4);
    root->left->right->left = newNode(3);
    root->right->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left = newNode(7);
 
    printf("Difference is : %d\n", difference(root));
 
    return 0;
}