#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, left child and right child */
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;
 
/* A utility function to check whether trees with roots as root1 and
   root2 are identical or not */
struct node* newNode(int data)
{
    struct node* node =
        (struct node*)malloc(sizeof(struct node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
    return(node);
}
 
int check(node *r1, node *r2)
{
    if(r1 != NULL && r2 != NULL)
    {
        if(r1->data == r2->data && check(r1->left, r2->left) &&
           r1->right, r2->right)
            return 1;
        else
            return 0;
    }

}

int isSubtree(node *r1, node *r2)
{
    if(r1 != NULL)
    {
        if(r1->data == r2->data && check(r1, r2))
            return 1;
       
        return isSubtree(r1->left, r2) || isSubtree(r1->right, r2);
    }
    else
        return 0;
}

int main()
{
    // TREE 1
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);
 
    // TREE 2
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);
 
 
    if (isSubtree(T, S))
        printf("Tree 2 is subtree of Tree 1\n");
    else
        printf("Tree 2 is not a subtree of Tree 1\n");
 
    return 0;
}