#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int adj[2000][2000], burnt[2000], btime[2000];

int main()
{
    ios_base::sync_with_stdio(0);   
    
    int m, a, b, i, j, w, x, y, mx = INT_MIN, vertexi, ans;

    scanf("%d %d %d", &m, &a, &b);

    for(i=0; i<m; i++)
    {
        scanf("%d %d %d", &x, &w, &y);
        adj[x][y]=w;
        adj[y][x]=w;
        mx = max(x, max(y, mx));
    }

    burnt[a] = 1;

    for(i=1; i<=mx; i++)
        btime[i] = INT_MAX;    

    for(i=1; i<=mx; i++)
    {
        if(adj[a][i] != 0)
        {
            btime[i] = min(adj[a][i], adj[i][a]);
        }
    }

    while(1)
    {
        int cnt=0, mn = INT_MAX;

        for(i=1; i<=mx; i++)
            if(burnt[i] == 1)
                cnt++;

        if(cnt == mx)
            break;

        for(i=1; i<=mx; i++)
        {
            if(btime[i] < mn && burnt[i] == 0)
                mn = btime[i], vertexi = i;
        }

        if(mn == INT_MAX)
            break;

        burnt[vertexi] = 1;

        for(j=1; j<=mx; j++)
        {
            if(adj[vertexi][j] == 0)
                continue;
            if(!burnt[j])
            {
                if(btime[vertexi] + adj[vertexi][j] < btime[j])
                    btime[j] = btime[vertexi] + adj[vertexi][j];
            }
        }
    }

    ans = btime[b];

    if(ans != INT_MAX)
        printf("YES\n%d", ans);
    else
        printf("NO");

    printf("\n");
    return 0;
}