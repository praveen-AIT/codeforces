#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}node;

void push(node **head, int no)
{
    node *temp = (node*)malloc(sizeof(node));
    
    temp->data = no;
    temp->next = *head;
    *head = temp;
    return;
}

void printlist(node *head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
    //return;
}

node *newNode(int data)
{
    node *new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

node* add_list(node *first, node *second)
{
    node *res = NULL, *prev=NULL;
    int carry = 0, sum;
    
    while(first != NULL || second != NULL)
    {
        node *temp = (node*)malloc(sizeof(node));
        sum = (first?first->data:0) + (second?second->data:0) + carry;
        carry = sum/10;
        sum = sum%10;

        temp->data = sum;
        temp->next = NULL;

        if(res == NULL)
        {
            res = temp;  
        }
        else
        {
            prev->next = temp;
        }

        prev = temp;
        if(first)
            first = first->next;
        if(second)
            second = second->next;       
    }
    
    return res;
}

int main()
{
    node *head1 = NULL, *head2 = NULL, *head3 = NULL;       

    push(&head1, 6);
    push(&head1, 4);
    push(&head1, 9);
    push(&head1, 5);
    push(&head1, 7);

    //push(&head2, 2);
    push(&head2, 4);
    push(&head2, 8);

    printlist(head1);
    printlist(head2);
    //cout<<head1->data;
    head3 = add_list(head1, head2);

    printlist(head3);
    return 0;
}