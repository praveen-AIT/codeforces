#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
 
using namespace std;
 
typedef struct Node
{
    int data;
    struct Node *left, *right;
}node;

void printLevelOrder(node *root)
{
    if(root == NULL)
        return;

    queue<node *>q;

    q.push(root);

    while(q.empty() == false)
    {
        node *temp = q.front();
        cout<<temp->data<<" ";
        q.pop();

        if(temp->left != NULL)
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }
}

node *new_node(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main(void)
{
    node *root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->right->right = new_node(5);

    printLevelOrder(root);
    cout<<endl;
    return (0);
}