#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 200010

int server[102], remaining;

int assign_server(int k, int t, int n, int d)
{
    int j=1, ans=0;
    for(int i=1; i<=n; i++)
        if(server[i] == 0 && j <= k)
            server[i] = t+d-1, ++j, ans += i, remaining--;
    return ans;
}

void free_server(int t, int n)
{
    int i, j;
    for(i=1; i<=n; i++)
        if(server[i] <= t && server[i] != 0)
            server[i] = 0, remaining++;
}

int main()
{
    int n, q, t, k, d, i, ans, temp;

    cin>>n>>q;
    temp = n;
    remaining = n;

    for(i=1; i<=q; i++)
    {
        cin>>t>>k>>d;

        free_server(t-1, n);

        int pt = t;

        if(k <= remaining)
        {
            ans = assign_server(k, t, n, d);
            cout<<ans<<endl;
        }
        else
            cout<<"-1"<<endl;

        if(i > 1)
            free_server(t, n);

    }
    return 0;
}