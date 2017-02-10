#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
 
typedef struct node
{
    int key;
    struct node *left, *right;
}node;

node *insert_node(node *root, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->key = data;
    temp->right = temp->left = NULL;

    if(root == NULL)
        return temp;
    

    if(data < root->key)
        root->left = insert_node(root->left, data);
    else if(data > root->key)
        root->right = insert_node(root->right, data);

    return root;
}

void inorder(node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->key);
        inorder(root->right);
    }
}

node *deletenode(node *root, int data)
{
    node *temp;

    if(root == NULL)
        return root;

    if(data < root->key)
        root->left = deletenode(root->left, data);
    else if(data > root->key)
        root->right = deletenode(root->right, data);

    else
    {
        if(root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;   
        }
        else
        {
            temp = root->right;
            while(temp->left != NULL)
                temp = temp->left;

            root->key = temp->key;
            root->right = deletenode(root->right, temp->key);
            return root;
        }
    }
}

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

node* newNode(int data)
{
    struct node* node = (struct node *)malloc(sizeof(struct node));
    node->key = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

node *first = NULL, *second = NULL;
int v1, v2=20;

void solve(node *root, int m, node *x, node *y)
{
    if(root != NULL)
    {
        solve(root->left, m, x, y);

        if(root->key < m)
        {
            if(first == NULL)
            {
                v1 = m;
                first = y;
                m = root->key;
            }
            else
            {
                v2 = root->key;
                second = root;
                m = root->key;
            }
        }
        else
        {
            m = root->key;
            y = root;
        }

        solve(root->right, m, x, y);
    }
}

int main()
{
    node *root = newNode(6), *x, *y;
    root->left        = newNode(10);
    root->right       = newNode(2);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(12);
    root->right->left = newNode(7);

    //scanf("%d %d", &k1, &k2);

    inorder(root);
    printf("\n");

    solve(root, INT_MIN, x, y);
    first->key = v2;
    second->key = v1;

    inorder(root);
    printf("\n");
    return 0;
}