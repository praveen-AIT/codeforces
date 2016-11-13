#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int getWeight(char ch) 
{
    switch (ch) 
    {
        case '^': return 3;
        case '/':
        case '*': return 2;
        case '+':
        case '-': return 1;
        default : return 0;
    }
}

void infix2postfix(char infix[], char postfix[], int size) 
{
    stack <char>s;
    int i=0, k=0;
    while(i < size)
    {
        if(infix[i] == '(')
        {
            s.push(infix[i]);
            i++;
            continue;
        }
        if(infix[i] == ')')
        {
            while(!s.empty() && s.top() != '(')
            {
                postfix[k++] = s.top();
                s.pop();
            }
            if(!s.empty()) 
            {
                s.pop();
            }
            i++;
            continue;
        }

        if(isalpha(infix[i]))
        {
            postfix[k++]=infix[i];
            i++;
        }
        else
        {
            while(!s.empty() && s.top()!='(' && getWeight(infix[i]) <= getWeight(s.top()))
            {
                postfix[k++] = s.top();
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    postfix[k++]='\0';
    cout<<postfix<<endl;
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        char infix[500];
        cin>>infix;
        int size = strlen(infix);
        char postfix[size+10];
        infix2postfix(infix,postfix,size);
    }
    return 0;
}