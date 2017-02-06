#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

ll minn(ll a, ll b, ll c)
{
    return min(a, min(b, c));
}

ll optimal_walk(int n, int a, int b, ll ans)
{
    if(n == 0)
        return ans;

    if(n%2 != 0)
        return optimal_walk(n-1, a, b, ans+a);
    else
        return min(optimal_walk(n/2, a, b, ans+b), 
                   optimal_walk(n-1, a, b, ans+a));
}

ll dp_optimal_walk(int n, int a, int b)
{
    ll dp[n+5], i;

    dp[0] = 0;

    for(i=1; i<=n; i++)
    {
        if(i%2 != 0)
        {
            dp[i] = minn(dp[i-1]+a, dp[(i-1)/2]+a+b, dp[(i+1)/2]+a+b);
        }
        else
        {
            dp[i] = min(dp[i/2]+b, dp[i-1]+a);
        }
    }
    return dp[n];
}

int main()
{   
    int n, a, b;
    ll ans;

    cin>>n>>a>>b;

    ans = dp_optimal_walk(n, a, b);
    cout<<ans<<endl;

    return 0;
}
