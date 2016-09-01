#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, q, i, ans=0, x;

    scanf("%d", &n);
    int a[100005] = {0};

    for(i=1; i<=n; i++)
    {
        scanf("%d", &x);
        a[x]++;
    }    
    for(i=1; i<=100005; i++)
        a[i] += a[i-1];

    scanf("%d", &q);
    for(i=1; i<=q; i++)
    {
        scanf("%d", &x);
        if(x > 100004)
            printf("%d\n", a[100004]);
        else
            printf("%d\n", a[x]);
    }
    return 0;
}