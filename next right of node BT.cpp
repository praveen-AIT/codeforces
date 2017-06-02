#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    struct node *left, *right;
    int data;
}node;

node* newNode(int key)
{
    node *temp = new node;
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

int height(node * root)
{
    if(root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh+1, rh+1);
}

void nextrightUtil(node *root, int level, int k, 
                  bool *found, node **res)
{
    if(root == NULL || level < 1)
        return;

    if(level == 1)
    {
        if(*found)
        {
            *found = false;
            *res = root;
        }

        if(root->data == k)
            *found = true;

        //return 0;
    }

    nextrightUtil(root->left, level-1, k, found, res);
    nextrightUtil(root->right, level-1, k, found, res);
} 

void nextright(node *root, int k)
{
    int h = height(root);
    bool found = false;
    node *res = NULL;

    for(int i=1; i<=h; i++)
    {
        nextrightUtil(root, i, k, &found, &res);
    }

    printf("%d\n", res->data);
}
 
int main()
{
    node *root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(6);
    root->right->right = newNode(5);
    root->right->right->right = newNode(25);
    root->left->left = newNode(8);
    root->left->left->left = newNode(15);
    root->left->right = newNode(4);

    nextright(root, 15);
    return 0;
}