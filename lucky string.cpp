#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, i;
    char a[10];
    cin>>n;
    a[0] = 'd';
    for(i=1; i<=n; i++)
    {
        if(i > 4)
        {
            //s.insert(i, char(96+i));
            cout<<a[i%4];
        }
            
        else
        {
            a[i] = char(96+i);
            cout<<a[i];
        } 
    }
    cout<<endl;
    return 0;
}

