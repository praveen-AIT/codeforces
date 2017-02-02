#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int sum(set<int> a, int p, int n)
{
    set<int>::iterator it;
    it = a.begin();

    for(int i=0; i<n; i++)
        it++;

    if(n < 0 && p != 0)
        return 0;

    if(p == 0)
        return 1;

    if(*it > p)
        return sum(a, n-1, p);
    else
        return 1 + min(sum(a, n-1, p-*it), sum(a, n-1, p));
}

int dp_sum(set<int> a, int n, int p)
{
    int i, j, dp[n+1][p+1];
    set<int>::iterator it;

    for(i=0; i<=n; i++)
        dp[i][0]=1;

    for(j=0; j<=p; j++)
        dp[0][j]=0;

    for(i=1; i<=n; i++)
    {
        it = a.begin();
        for(int k=0; k<i-1; k++)
            it++;

        for(j=1; j<=p; j++)
        {            
            if(*it > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = 1 + min(dp[i-1][j-*it], dp[i-1][j]);
        }
    }
    return dp[n][p]-1;
}

int main()
{   
    int t, n, i, ans, p, x, y, t1, t2;
    set<int> a;
    set<int>::iterator it;
    
    cin>>t;
    while(t--)
    {
        cin>>p>>x>>y;
        t1 = x, t2 = y;

        while(t1 <= p)
        {
            a.insert(t1);
            t1 *= x;
        }

        while(t2 <= p)
        {
            a.insert(t2);
            t2 *= y;
        }

        a.insert(1);
        
        ans = dp_sum(a, a.size(), p);
        cout<<ans<<endl;
        a.clear();
    }
    return 0;
}