#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m, i, j, ans=0, x[15] = {0}, a, b;
    cin>>n>>m;

    for(i=1; i<=m; i++)
    {
        cin>>a>>b;
        x[b] += a;
    }

    i=10;
    while(i>0)
    {
        if(x[i] > 0)
        {
            //cout<<i<<endl;
            if(n > x[i])
            {
                n = n - x[i];
                ans += x[i]*i;
            }
            else if(n < x[i])
            {
                ans += n*i;
                break;
            }
            else if(n == x[i])
            {
                ans += n*i;
                break;
            }
        }
        i--;
    }
    cout<<ans<<endl;
    return 0;
}