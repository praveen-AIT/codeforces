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
    node *temp = (node*)malloc(sizeof(node)), *new_node;

    temp->data = no;
    temp->next = NULL;

    if(*head == NULL)
    {
        *head=temp;
        return;
    }

    new_node = *head;
    while(new_node->next != NULL)
        new_node = new_node->next;

    new_node->next = temp;
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

void remove_loop(node *slowp, node *head)
{
    node *ptr1, *ptr2;
    ptr1 = head;
    ptr2 = slowp;

    while(1)
    {
        ptr2 = slowp;
        while(ptr2->next != ptr1 && ptr2->next != slowp)
            ptr2 = ptr2->next;
        
        if(ptr2->next == ptr1)
        {
            ptr2->next = NULL;
            break;
        }
        else
            ptr1 = ptr1->next;
    }
}

int detect_loop(node *head)
{
    node *slowp, *fastp;
    slowp = head, fastp = head;

    while(slowp && fastp && fastp->next)
    {
        slowp = slowp->next;
        fastp = fastp->next->next;

        if(slowp == fastp)
        {
            remove_loop(slowp, head);
            return 1;
        }
    }
    return 0;
}

int main()
{
    node *head = NULL, *temp;       

    push(&head, 6);
    push(&head, 4);
    push(&head, 9);
    push(&head, 5);
    push(&head, 7);

    head->next->next->next->next->next = head->next->next;

    int x = detect_loop(head);
    if(x)
        cout<<"LOOP FOUND"<<endl;
    else
        cout<<"NO LOOP"<<endl;

    printlist(head);

    return 0;
}