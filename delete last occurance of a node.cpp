#include <bits/stdc++.h>

using namespace std;   
typedef struct node
{
    int data;
    struct node *next;
}node;

int detectloop(node *root);
void push(node **, int);
void printList(node *);
void deleteLast(node **, int);
node *newNode(int);

int main()
{
    node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(5);
    head->next->next->next->next = newNode(2);
    head->next->next->next->next->next = newNode(10);
    head->next->next->next->next->next->next = newNode(2);
 
    puts("Created Linked List: ");
    printList(head);
    deleteLast(&head, 2);
    puts("\nLinked List after Deletion of 1: ");
    printList(head);          

    return 0;
}

void deleteLast(node **head, int key)
{
    node *last_ptr = NULL, *current = *head, *temp = *head;

    if((*head)->data == key)
        last_ptr = *head;

    while(temp->next != NULL)
    {
        if(temp->next->data == key)
        {
            last_ptr = temp;
        }

        temp = temp->next;
    }

    if(last_ptr != *head)
        last_ptr->next = last_ptr->next->next;
    else
    {
        *head = (*head)->next;
        delete last_ptr;
    }
}

void push(node** head_ref, int new_data)
{
    node* new_node = (node *) malloc(sizeof(node));
 
    new_node->data  = new_data;
 
    new_node->next = (*head_ref);
 
    (*head_ref)    = new_node;
}
 
void printList(node *root)
{
    while(root != NULL)
    {
        printf("%d ", root->data);
        root = root->next;
    }
    printf("\n");
}

struct node *newNode(int new_data)
{
    node *new_node = (node*) malloc(sizeof(node));
 
    new_node->data  = new_data;
    new_node->next =  NULL;
 
    return new_node;
}