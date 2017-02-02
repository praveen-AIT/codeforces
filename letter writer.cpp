#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int min_hours(int n, int x, int y)
{
    if(n < 10 || n == 11)
        return 1e8;

    if(n == 10 || n == 12)
        return 1;

    return 1 + min(min_hours(n-x, x, y), min_hours(n-y, x, y));
}

int dp_min_hours(int n, int x, int y)
{
    int i, dp[n+1];

    if(n < 10 || n == 11)
        return -1;

    for(i=0; i<10; i++)
        dp[i] = 1e8;

    dp[11] = 1e8;
    dp[10] = 1, dp[12] = 1;

    for(i=13; i<=n; i++)
    {
        dp[i] = 1 + min(dp[i-x], dp[i-y]);
    }
    if(dp[n] >= 1e8)
        return -1;
    return dp[n];
}

int main()
{   
    int n, x = 12, y = 10, i, ans, t;

    cin>>t;

    while(t--)
    {
        cin>>n;

        ans = dp_min_hours(n, x, y);
        cout<<ans<<endl;
    }

    return 0;
}