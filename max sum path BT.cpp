#include <stdio.h>
#include <limits.h>
 
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;
 
bool print_maxpath (struct node *root, struct node *target_leaf)
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

void maxpath(node *root, int *max_sum, int cur_sum, node **node_ref)
{
    if(root == NULL)
        return;

    cur_sum += root->data;

    if(root->left == NULL && root->right == NULL)
    {
        if(cur_sum > *max_sum)
        {
            *max_sum = cur_sum;
            *node_ref = root;
        }
    }
    maxpath(root->left, max_sum, cur_sum, node_ref);
    maxpath(root->right, max_sum, cur_sum, node_ref);
}
 
int maxSumPath(node *root)
{
    if(root == NULL)
        return 0;

    node *node_ref;
    int max_sum = INT_MIN;

    maxpath(root, &max_sum, 0, &node_ref);

    print_maxpath(root, node_ref);
    return max_sum;
}

int main()
{
    struct node *root = NULL;
 
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(12);
 
    printf ("Following are the nodes on the maximum "
            "sum path \n");
    int sum = maxSumPath(root);
    printf ("\nSum of the nodes is %d \n", sum);
 
    return 0;
}