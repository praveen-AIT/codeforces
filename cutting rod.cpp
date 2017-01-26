#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int cutting_rod(int a[], int cost[], int ind, int len)
{
    if(len <= 0 || ind < 0)
        return 0;

    if(len < a[ind])
        return cutting_rod(a, cost, ind-1, len);
    else
        return max(cost[ind] + cutting_rod(a, cost, ind, len-a[ind]), 
                    cutting_rod(a, cost, ind-1, len)
                  );
}

int dp_cuttingrod(int cost[], int n)
{
    int dp[n+1][n+1] = {0}, i, j;

    for(i=0; i<=n; i++)
        dp[0][i]=0;

    for(i=0; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i == 0)
                dp[i][j]=0;
            else
            {
                if(j < i)
                    dp[i][j] = dp[i-1][j];
    
                else
                    dp[i][j] = max(cost[i-1] + dp[i][j-i], dp[i-1][j]);
            }
        }
    }
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=n; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[n][n];
}

int main()
{   
    int i, j, n;

    cin>>n;
    int a[n+2], cost[n+2];

    for(i=0; i<n; i++)
        cin>>cost[i];

    int ans = dp_cuttingrod(cost, n);

    cout<<ans<<endl;
    return 0;
}