#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, i, ans=0, b = INT_MAX;

    scanf("%d",  &n);
    int a[n+5];
    for(i=1; i<=n; i++)
        scanf("%d", &a[i]);

    for(i=2; i<=n; i++)
    {
        ans += (a[i-1] - a[i]);
        if(ans < b)
            b = ans;
    }
    //printf("%d\n", b);
    if(b>0)
        printf("%d\n", a[1]);
    else
        printf("%d\n", a[1]+abs(b));

    return 0;
}