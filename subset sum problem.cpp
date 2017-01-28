#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int subset_sum(int a[], int n, int x)
{
    if(n < 0 && x != 0)
        return 0;

    if(x == 0)
        return 1;

    if(a[n] > x)
        return subset_sum(a, n-1, x);
    else
        return subset_sum(a, n-1, x-a[n]) || subset_sum(a, n-1, x);
}

int dp_subset_sum(int a[], int n, int x)
{
    int i, j, dp[n+1][x+1];

    for(i=0; i<=x; i++)
        dp[0][i]=0;

    for(i=0; i<=n; i++)
        dp[i][0]=1;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=x; j++)
        {
            if(a[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
        }
    }
    return dp[n][x];
}

int main()
{   
    int n, i, x;
    cin>>n;

    int a[n+1];

    for(i=0; i<n; i++)
        cin>>a[i];
    cin>>x;

    int ans = dp_subset_sum(a, n, x);
    cout<<ans<<endl;

    return 0;
}
