#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define ll unsigned long long int
#define R 3
#define C 3

using namespace std;

int min_path(int a[R][C], int n, int m)
{
    if (n < 0 || m < 0)
      return INT_MAX;   
    if(n == 0 && m == 0)
        return a[n][m];

    else
        return a[n][m] + min(min_path(a, n-1, m-1),
                               min(min_path(a, n-1, m), 
                                    min_path(a, n, m-1) ));
}

int dp_minpath(int a[R][C], int n, int m)
{
    int dp[n+1][m+1]={0}, i, j;

    dp[0][0] = a[0][0];

    for(i=1; i<=n; i++)
        dp[i][0] = dp[i-1][0] + a[i][0];
    for(i=0; i<=m; i++)
        dp[0][i] = dp[0][i-1] + a[0][i];

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            dp[i][j] = a[i][j] + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        }
    }

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=m; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[n][m];
}

int main()
{   
    int n, i, j, a[10][10], ans;
    int cost[R][C] = { {1, 2, 3},
                      {3, 8, 5},
                      {1, 0, 3} };
    cout<<dp_minpath(cost, 2, 2);

    cout<<endl;

    return 0;
}