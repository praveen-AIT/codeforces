#include <bits/stdc++.h>
#define ll long long
using namespace std;

int mask(int n)
{
    int temp, a, ans=0, cnt=1;
    a = n;
    while(a > 0)
    {
        temp = a%10;
        a = a/10;
        if(temp == 7 || temp == 4)
        {
            ans += temp*cnt;
            cnt = cnt*10;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int a, b, ans;
    scanf("%d%d", &a, &b);
    ans = a + 1;
    while(mask(ans) != b)
    {
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}