#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m=INT_MIN, i, ans=0, j;
    scanf("%d", &n);
    int cnt[10] = {0}, p1, p2, p3;

    for(i=1; i<=n; i++)
    {
        scanf("%d", &j);
        cnt[j]++;
    }
    ans = cnt[4];
    ans += cnt[3];
    cnt[1] = max(cnt[1] - cnt[3] , 0 );
    ans += cnt[2]/2;
    int r = cnt[2]%2;
    if( r ) {
        ans ++;
        cnt[1] = max(0,cnt[1] - 2);
    }
    
    if( cnt[1] ) {
        if( cnt[1]%4 == 0) ans += cnt[1] / 4;
        else ans += cnt[1] / 4 + 1;
    }
    
    printf("%d\n" ,ans );
    return 0;
}