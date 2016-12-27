// C/C++ program to rotate a linked list counter clock wise
 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
 
typedef struct node
{
    int data;
    struct node* next;
}node;

/* Function to push a node */
void push (struct node** head_ref, int new_data)
{
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    new_node->data  = new_data;
 
    new_node->next = (*head_ref);
 
    (*head_ref)    = new_node;
}
 
/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
 
void rotate(node **head, int k)
{
    node *p1, *p2, *p3;
    p1 = *head;
    p2 = *head;

    for(int i=1; i<k; i++)
        p1 = p1->next;

    p3 = p1;
    *head = p3->next;

    while(p1->next != NULL)
        p1 = p1->next;

    p1->next = p2;
    p3->next = NULL;

}

int main(void)
{
    struct node* head = NULL;
 
    for (int i = 60; i > 0; i -= 10)
        push(&head, i);
 
    printf("Given linked list \n");
    printList(head);
    
    rotate(&head, 4); 

    printf("\nRotated Linked list \n");
    printList(head);
 
    return (0);
}