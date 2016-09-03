#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, x=0, y=0, cnt=0, i, j, cur;

    cin>>n>>m;
    int u[1002] = {0}, v[1002] = {0};
    char a[1002][1002];

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            cin>>a[i][j];
    for(i=1; i<=n; i++)
    {
        cur=0;
        for(j=1; j<=m; j++)
        {
            if(a[i][j] == '*')
            {
                cur++, ++cnt;
            }    
        }
        u[i] = cur;
    }
    for(i=1; i<=m; i++)
    {
        cur=0;
        for(j=1; j<=n; j++)
        {
            if(a[j][i] == '*')
            {
                //cout<<i<<j;
                ++cur, ++cnt;
            }
        }
        v[i] = cur;
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(u[i] + v[j] - (a[i][j] == '*') == cnt)
            {
                printf("YES\n%d %d\n", i, j);
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}