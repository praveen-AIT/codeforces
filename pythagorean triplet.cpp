#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    ll n, a, b;
    cin>>n;
    if(n%2 == 0)
    {
        if((n/2)%2 != 0)
        {
            n = n/2;
            a = (pow(n, 2)-1)/2;
            b = a+1;
            if(n == a || n == b)
                return 0, printf("-1\n");
            printf("%lld %lld\n", 2*a, 2*b);
            return 0;    
        }
        n = n/2;
        a = n*n-1;
        b = n*n+1;
        if(n == a || n == b)
                return 0, printf("-1\n");
        printf("%lld %lld\n", a, b);
        return 0;
    }
    a = (pow(n, 2)-1)/2;
    b = a+1;
    if(n == a || n == b)
        return 0, printf("-1\n");
    printf("%lld %lld\n", a, b);
    return 0;
}