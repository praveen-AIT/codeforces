#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int min_time(int a[], int n, int k)
{
    if(n < 0)
        return 0;

    if(k == 1)
        return min_time(a, n-1, 0) + a[n];
    else
        return min(min_time(a, n-1, 1), min_time(a, n-1, 0) + a[n]);
}

int dp_min_time(int a[], int n)
{
    int i, j, k, dp[n+1][2];

    dp[0][0] = 0, dp[0][1] = 0;

    for(i=1; i<=n; i++)
    {
        for(k=0; k<=1; k++)
        {
            if(k == 1)
                dp[i][k] = a[i-1] + dp[i-1][0];
            else
                dp[i][k] = min(dp[i-1][1], dp[i-1][0] + a[i-1]);
        }
    }
    return dp[n][0];
}

int main()
{   
    int t, n, i;

    cin>>t;
    while(t--)
    {
        cin>>n;

        int a[n+2], ans1=0, ans2=0;

        for(i=0; i<n; i++)
            cin>>a[i];

        cout<<dp_min_time(a, n)<<endl;
    }
    
    return 0;
}
