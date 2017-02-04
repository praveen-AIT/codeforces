#include <stdio.h>
#include <stdlib.h>
 
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

int lca(node *root, int k1, int k2)
{
    if(root == NULL)
        return 0;

    if(root->key > k1 && root->key < k2)
        return root->key;

    else if(root->key < k1 && root->key < k2)
        lca(root->right, k1, k2);
    else if(root->key > k1 && root->key > k2)
        lca(root->left, k1, k2);
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

    printf("Enter the two key values\n");
    scanf("%d %d", &k1, &k2);

    printf("%d\n", lca(root, k1, k2));

    return 0;
}