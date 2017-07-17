#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h> 

using namespace std;

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;
 
node* newNode(int );

int height(node *root)
{
    if(root == NULL)
        return 0;

    return 1 + max(height(root->right), height(root->left));
} 
 
void printInorder(struct node* node)
{
     if (node == NULL)
          return;
     printInorder(node->left);
     printf("%d ", node->data);
     printInorder(node->right);
}

node* newNode(int data)
{
    node* Node = (node*)malloc(sizeof(node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return(Node);
} 

void verticalUtil(node *root, int hd, map<int, int> &m)
{
    if(root == NULL)
        return ;

    m[hd] += root->data;

    verticalUtil(root->left, hd-1, m);
    verticalUtil(root->right, hd+1, m);
}

void verticalSum(node *root)
{
    map<int, int> m;
    map<int, int> :: iterator it;

    if(root == NULL)
        return;

    verticalUtil(root, 0, m);

    for(it = m.begin(); it != m.end(); it++)
        cout<<it->first<<" "<<it->second<<endl;
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
 
    cout << "Following are the values of vertical sums with the positions of the columns with respect to root\n";
    verticalSum(root);    

    cout<<endl;
    return 0;
}