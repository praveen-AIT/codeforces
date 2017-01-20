#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define ll unsigned long long int
#define NUM_BITS_INT 32

using namespace std;
int a[100006]={0};

int operations(string s, string r, int m, int n)
{
    if(m == 0)
        return n;
    if(n == 0)
        return m;

    if(s[m-1] == r[n-1])
        return operations(s, r, m-1, n-1);

    return 1 + min( operations(s, r, m-1, n), min( operations(s, r, m, n-1), 
        operations(s, r, m-1, n-1)));
}

int dp_operations(string s, string r, int m, int n)
{
    int dp[m+1][n+1], i, j;

    for(i=0; i<=m; i++)
        dp[0][i]=i;

    for(i=0; i<=n; i++)
        dp[i][0]=i;

    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(s[i] == r[j])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
        }
    }
    
    return dp[m][n];
}

int main()
{   
    int n, i;
    string s, r;

    cin>>s>>r;

    int ans = dp_operations(s, r, s.length(), r.length());

    cout<<ans<<endl;

    return 0;
}