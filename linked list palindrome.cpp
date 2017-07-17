#include <bits/stdc++.h>

using namespace std;   
typedef struct node
{
    string data;
    struct node *next;
}node;

int detectloop(node *root);
void push(node **, int);
void printList(node *);
int isPalindrome(node *);
node *newNode(string);

int main()
{
    node *head = newNode("a");
    head->next = newNode("bc");
    head->next->next = newNode("d");
    head->next->next->next = newNode("dcb");
    head->next->next->next->next = newNode("a");
 
    isPalindrome(head)? printf("true\n"): printf("false\n");          

    return 0;
}

int isPalindrome(node *head)
{
    node *temp = head;

    string s = "", r;

    while(temp != NULL)
    {
        s.append(temp->data);
        temp = temp->next;
    }

    cout<<s<<endl;  
    r = s;
    reverse(r.begin(), r.end());

    if(r != s)
        return 0;
    
    return 1;
}

int detectloop(node *root)
{
    node *fast_p, *slow_p;
    slow_p = root;
    fast_p = slow_p;

    while(slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;

        if(slow_p == fast_p)
        {
            cout<<"Loop found "<<slow_p->data<<endl;
            return 1;
        }
    }

    cout<<"No Loop"<<endl;
    return 0;
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
        cout<<root->data<<" ";
        root = root->next;
    }
    printf("\n");
}

struct node *newNode(string new_data)
{
    node *new_node = new node;
 
    new_node->data  = new_data;
    new_node->next =  NULL;
 
    return new_node;
}