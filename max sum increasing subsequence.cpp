#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int max_sis(int a[], int c, int n, int maxn)
{
    if(c == n)
        return 0;

    if(a[c] < maxn)
        return max_sis(a, c+1, n, maxn);
    else
        return max(a[c] + max_sis(a, c+1, n, a[c]), 
                    max_sis(a, c+1, n, maxn));
}

int dp_msis(int a[], int n)
{
    int dp[n], i, j, ans=INT_MIN;

    for(i=0; i<n; i++)
        dp[i] = a[i];

    for(i=1; i<n; i++)
        for(j=0; j<i; j++)
            if(a[i] > a[j] && dp[i] < dp[j] + a[i])
                dp[i] += dp[j];
        
    for(i=0; i<n; i++)
        ans = max(dp[i], ans);
    return ans;
}

int main()
{   
    int n, m, i, ans;
    int a[n+2];

    cin>>n;

    for(i=0; i<n; i++)
        cin>>a[i];

    ans = max_sis(a, 0, n, 0);

    cout<<ans<<endl;
    return 0;
}