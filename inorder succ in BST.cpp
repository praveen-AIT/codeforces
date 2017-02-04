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

void inorder_succ(node *root, int data, node * &succ)
{
    int ans;

    if(root == NULL)
        return;

    if(data == root->key)
    {
        if(root->right != NULL)
        {
            node *temp = root->right;
            while(temp->left != NULL)
                temp = temp->left;
            succ = temp;
        }
    }
    else if(data > root->key)
        inorder_succ(root->right, data, succ);
    else if(data < root->key)
        inorder_succ(root->left, data, succ);

}

int main()
{
    node *root=NULL, *temp, *succ;
    int data, n, del, ans;

    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &data);
        root = insert_node(root, data);
    }

    inorder(root);
    printf("\n");

    printf("Whose inorder successor u want to know ??\n");
    scanf("%d",&del);
    inorder_succ(root, del, succ);
    printf("%d\n", succ->key);

    return 0;
}