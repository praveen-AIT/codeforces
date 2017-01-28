#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int dp_common(string s, string r, int l1, int l2)
{
    int dp[l1+1][l2+1] = {0}, i, j, result=0;

    for(i=0; i<=l1; i++)
        dp[0][i]=0;

    for(i=0; i<=l2; i++)
        dp[i][0]=0;

    for(i=1; i<=l1; i++)
    {
        for(j=1; j<=l2; j++)
        {
            if(s[i-1] == r[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

            result = max(result, dp[i][j]);
        }
        
    }
    
    return result;
}

int main()
{   
    int ans, i, t, l, m;
    string s, r;

    cin>>t;
    while(t--)
    {
        cin>>l>>m;
        cin>>s>>r;

        ans = dp_common(s, r, l, m);

        cout<<ans<<endl;
    }
    return 0;
}