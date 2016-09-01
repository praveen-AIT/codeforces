#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, i, j, x, tx, ty, s=0, s2=0;
    ll sum1=0, sum2=0, ans, rs=0, cs=0, tcs=0, trs=0;
    bool flag = 1;
    scanf("%lld", &n);
    ll a[n+5][n+5];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>a[i][j];
            if(a[i][j] == 0)
                tx=i, ty=j;
        }
    }
    if(n == 1LL)
    {
        printf("1\n");
        return 0;
    }
    x = tx+1;
    if(x == n)
        x=0;
    cout<<tx<<ty<<x<<endl;
    for(i=0; i<n; i++)
        s += a[x][i];
    for(i=0; i<n; i++)
        s2 += a[tx][i];

    ans = s - s2;
    
    if(ans <= 0)
    {
        printf("-1\n");
        return 0;
    }
    //cout<<sum1<<" "<<sum2<<" "<<colsum<<endl;
    
    a[tx][ty] = ans;
    for(i=0; i<n; i++)
    {
        rs = 0, cs = 0;
        for(j=0; j<n; j++)
        {
            rs += a[i][j];
            cs += a[j][i];
        }
        //cout<<rs<<" "<<cs<<endl;
        if(rs != s)
            flag = 0;
        if(cs != s)
            flag = 0;
    }
    ll dd1=0, dd2=0;
    for(i=0; i<n; i++)
    {
        dd1 += a[i][i];
        dd2 += a[i][n-1-i];
    }
    if(dd1 != s)
        flag = 0;
    if(dd2 != s)
        flag = 0;
    //cout<<dd2<<" "<<dd1<<endl;
    if(flag != 0)
        printf("%lld\n", ans);
    else
        printf("-1\n");
    return 0;
}