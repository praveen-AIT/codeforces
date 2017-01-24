#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int min_ways(int floors, int eggs)
{
    if(floors == 0 || floors == 1)
        return floors;

    if(eggs == 1)
        return floors;

    int ans, m = INT_MAX;

    for(int i=1; i<=floors; i++)
    {
        ans = max(min_ways(i-1, eggs-1), min_ways(floors-i, eggs));
        if(ans < m)
            m = ans;
    }
    return m+1;
}

int dp_minways(int eggs, int floors)
{
    int dp[eggs+1][floors+1], i, j, k, res, m;

    for(i=1; i<=eggs; i++)
        dp[i][1]=1, dp[i][0]=0;

    for(i=1; i<=floors; i++)
        dp[1][i]=i;

    for(i=2; i<=eggs; i++)
    {
        for(j=2; j<=floors; j++)
        {
            m = INT_MAX;
            for(k=1; k<=j; k++)
            {
                dp[i][j] = min(m, 1 + max(dp[i-1][k-1], dp[i][j-k]));
                m = dp[i][j];
            }
        }
    }
    for(i=1; i<=eggs; i++)
    {
        for(j=1; j<=floors; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[eggs][floors];
}

int main()
{   
    int floors, eggs, i;

    cin>>eggs>>floors;
    int ans = dp_minways(eggs, floors);

    cout<<ans<<endl;
    return 0;
}