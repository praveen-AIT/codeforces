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
 
void printArray(vector<int>);
void printPathsRecur(node*, vector<int>);
node* newNode(int );
void printPaths(node*);
 
 
node* newNode(int data)
{
    node* Node = (node*)malloc(sizeof(node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return(Node);
} 
 
void printPaths(node *root)
{
    vector<int> v;
    printPathsRecur(root, v);
}

void printPathsRecur(node *root, vector<int> v)
{
    if(root == NULL)
        return;

    v.push_back(root->data);

    if(root->left == NULL && root->right == NULL)
        printArray(v);
    else
    {
        printPathsRecur(root->left, v);
        printPathsRecur(root->right, v);
    }
}

void printArray(vector<int> v)
{
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

int main()
{
    node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5); 

    printPaths(root);

    return 0;
}