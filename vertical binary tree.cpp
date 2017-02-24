#include <stdio.h>
#include <limits.h>
#include <bits/stdc++.h>
 
using namespace std;

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

void getVerticalOrder(node *root, int hd, map<int, vector<int> > &hash)
{
    if(root == NULL)
        return;

    hash[hd].push_back(root->data);

    getVerticalOrder(root->left, hd-1, hash);
    getVerticalOrder(root->right, hd+1, hash);
}

void printVerticalOrder(node *root)
{
    map<int, vector<int> >hash;

    getVerticalOrder(root, 0, hash);

    map<int, vector<int> > :: iterator it;    
    for(it= hash.begin(); it != hash.end(); it++)
    {
        for(int i=0; i<it->second.size(); i++)
            cout<<it->second[i]<<" ";
        cout<<endl;
    }
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
    
    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
 
    return 0;
}