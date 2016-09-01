#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll ans=0;
    int n, x, i;
    scanf("%d", &n);

    int a[n+5] = {0};

    for(i=1; i<=n; i++)
    {
        scanf("%d", &x);
        a[x] = i;
    }

    for(i=1; i<n; i++)
    {
        ans += abs(a[i]-a[i+1]);
    }
    printf("%lld\n", ans);
    return 0;
}