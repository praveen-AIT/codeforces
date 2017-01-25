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
            if(wt[i] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(val[i] + dp[i-1][j-wt[i]], dp[i-1][j]);
        }
    }          
    return dp[n][W];
}

int palind_subseq(char a[], int m, int n)
{
    if(m > n)
        return 0;

    if(m == n)
        return 1;

    if(a[m] == a[n])
        return 2 + palind_subseq(a, m+1, n-1);

    else
        return max(palind_subseq(a, m, n-1), 
                        palind_subseq(a, m+1, n));
}

int dp_palindsubseq(char a[], int n)
{
    int i, j, dp[n+1][n+1]={0};

    for(i=0; i<=n; i++)
        dp[i][i]=1;

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=n-i; j++)
        {
            if(i > j)
                dp[i][j] = 0;
            
            else if(a[i] == a[j])
                dp[i][j] = 2 + dp[i+1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
        }
    }

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=n; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][n];
}

int main()
{   
    int n, m;
    char a[]="GEEKSFORGEEKS";
    n = strlen(a);

    int ans = dp_palindsubseq(a, n-1);

    cout<<ans<<endl;
    return 0;
}