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

int isBSTUtil(struct node* node, int min, int max) 
{ 
  if (node==NULL) 
     return 1;
       
  if (node->key < min || node->key > max) 
     return 0; 
 
    isBSTUtil(node->left, min, node->key-1) &&  
    isBSTUtil(node->right, node->key+1, max); 
}

int isBST(struct node* node) 
{ 
  return(isBSTUtil(node, INT_MIN, INT_MAX)); 
} 

int size(node *root)
{
    if(root == NULL)
        return 0;
    else
        return (size(root->left) + size(root->right) + 1);
}

int largest_bst(node *root)
{
    if(isBST(root))
        return size(root);
    else
        return max(largest_bst(root->left), largest_bst(root->right));
}

int main()
{
    node *root=NULL, *temp, *succ;
    int data, n, k1, k2;

    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &data);
        root = insert_node(root, data);
    }

    inorder(root);
    printf("\n");

    printf("%d\n", isBST(root));
    printf("%d\n", size(root));
    printf("%d\n", largest_bst(root));

    return 0;
}