#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int partition(int a[], int n, int sum)
{
    if(n < 0)
        return 0;

    if(sum == 0)
        return 1;
    
    if(a[n-1] > sum)
        return partition(a, n-1, sum);
    else
        return max(
                   partition(a, n-1, sum - a[n]), 
                   partition(a, n-1, sum)
                  );

}

int dp_partition(int a[], int sum, int n)
{
    int i, j, dp[n+1][sum+1];

    for(i=0; i<=sum; i++)
        dp[0][i]=0;

    for(i=0; i<=n; i++)
        dp[i][0]=1;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=sum; j++)
        {
            if(a[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j-a[i-1]], dp[i-1][j]);   
        }
    }
    return dp[n][sum];
}

int main()
{   
    int i, ans=0, n, sum=0;

    cin>>n;
    int a[n+2];

    for(i=0; i<n; i++)
    {
        cin>>a[i];
        sum += a[i];
    }

    if(sum%2 == 0)
        ans = dp_partition(a, sum/2, n);
    cout<<ans<<endl;

    return 0;
}
