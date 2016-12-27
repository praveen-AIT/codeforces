#include <stdio.h>
#include <stdlib.h>
#include <iostream>
 
using namespace std;
 

int main(void)
{
    int n, i, j;
    string s;

    cin>>n>>s;

    for(i=1; i<=n; i++)
    {
        if(n-2*i >= 0)
        {
            cout<<s[n-2*i];
            s.erase(s.begin() + n - 2*i);
        }
        if(n-2*i < 0)
        {
            for(j=0; j<s.length(); j++)
                cout<<s[j];
            break;
        }
    }
    cout<<endl;
    return (0);
}