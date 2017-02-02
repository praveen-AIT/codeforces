#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int solve(int n, int a, int b)
{
    if(n < 0)
        return 0;

    if(n == 0)
        return 1;

    if(b > n)
        return solve(n-a, a, b);
    else
        return solve(n-a, a, b) + solve(n-b, a, b);
}

ll dp_solve(int n, int a, int b)
{
    int i, dp[n+1];

    dp[0] = 1;
    

    for(i=1; i<=n; i++)
    {
        if(b > i)
            dp[i] = dp[i-a];
        else
            dp[i] = dp[i-a] + dp[i-b];
    }
    return dp[n];
}

int main()
{   
    int n;

    cin>>n;

    ll ans = dp_solve(n, 1, 2);

    cout<<ans<<endl;
    
    return 0;
}
