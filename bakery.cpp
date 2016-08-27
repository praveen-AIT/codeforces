#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, k, i, ans=INT_MAX, x;

    scanf("%d%d%d", &n, &m, &k);
    int a[100005], b[100005], c[100005];
    int d[100005] = {0};
    for(i=1; i<=m; i++)
    {
        scanf("%d%d%d" ,&a[i], &b[i], &c[i]);
    }
    for(i=1; i<=k; i++)
    {
        scanf("%d", &x);
        d[x] = 1;
    }
    for(i=1; i<=m; i++)
    {
        if(d[a[i]] != d[b[i]])
            ans = min(ans, c[i]);
    }
    if(ans == 0|| ans == INT_MAX)
        printf("-1\n");
    else
        printf("%d\n", ans);
    return 0;
}