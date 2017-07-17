#include <bits/stdc++.h>
 
using namespace std;   

int main()
{
    int n, a, b, i;

    cin>>n>>a>>b;

    int v[n+10];

    for(i=0; i<n; i++)
        cin>>v[i];

    sort(v, v+n);

    int x, y;
    x = v[n-a];
    y = v[n-a-1];

    cout<<x-y<<endl;
}