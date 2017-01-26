#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int knapsack(int val[], int wt[], int n, int W)
{
    if(n == 0 || W == 0)
        return 0;

    if(wt[n] > W)
        return knapsack(val, wt, n-1, W);

    else
        return max( val[n] + knapsack(val, wt, n-1, W-wt[n]), 
                    knapsack(val, wt, n-1, W));
}

int dp_knapsack(int val[], int wt[], int n, int W)
{
    int i, j, dp[n+1][W+1]={0};

    for(i=0; i<=n; i++)
        dp[i][0]=0;

    for(i=0; i<=W; i++)
        dp[0][i]=0;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=W; j++)
        {
            if(wt[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], 
                               dp[i-1][j]);
        }
    }          
    return dp[n][W];
}

int main()
{   
    int n, i, a[100], b[100], W;

    cin>>n>>W;

    for(i=0; i<n; i++)
        cin>>a[i];

    for(i=0; i<n; i++)
        cin>>b[i];

    int ans = dp_knapsack(a, b, n, W);
    cout<<ans<<endl;
    return 0;
}