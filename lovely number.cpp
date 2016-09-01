#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll prime(ll n)
{
    ll i, j=0, ans=1;
    while(n%2 == 0)
    {
        n = n/2;
        j++;
    }
    if(j != 0)
        ans *= 2;
    j=0;
    for(i=3; i<= sqrt(n); i+=2)
    {
        j=0;
        while(n%i == 0)
        {
            n = n/i;
            j++;
        }
        if(j != 0)
            ans *= i;
    }
    if(n > 2)
        ans *= n;
    return ans;
}

int main()
{
    ll n, i, ans;

    cin>>n;
    if(n == 1)
        ans=1;
    else
        ans = prime(n);
    printf("%lld\n", ans);
    return 0;
}