#include <bits/stdc++.h>
#define ll unsigned long long

using namespace std;

int prime(ll n)
{
    ll i, j=0;
    if(n == 2)
        return 1;
    if(n == 1)
        return 0;
    while(n%2 == 0)
    {
        n = n/2;
        j++;
    }
    if(j != 0)
        return 0;
    j=0;
    for(i=3; i<= sqrt(n); i+=2)
    {
        j=0;
        while(n%i == 0)
        {
            n = n/i;
            j++;
        }
        if(j == 0)
            continue;
        return 0;
    }
    if(n > 2)
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    ll n, a, b, i;
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%lld %lld", &a, &b);
        for(i=a; i<=b; i++)
            if(prime(i))
                printf("%lld\n", i);
        printf("\n");
    }
    return 0;
}