#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    
    ll a, b, ans=0, i, x, y, j;

    cin>>a>>b;

    for(i=2; i<=70; i++)
    {
        ll y=1;
        x = pow(2, i) - 1;
        for(j=0; j<=(i-2); j++)
        {
            y = 1LL << j;
            if((x-y) >= a && (x-y) <= b)
                ++ans;         
        }
    }

    cout<<ans<<endl;
    return 0;
}