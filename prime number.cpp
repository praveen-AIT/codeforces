#include <bits/stdc++.h>
#define ll unsigned long long

using namespace std;

ll a[1000] = {0};

void prime(ll n)
{
    ll i, j=0;
    while(n%2 == 0)
    {
        //a[j] = 2;
        n = n/2;
        j++;
    }
    if(j != 0)
        printf("2^%lld ", j);
    j=0;
    for(i=3; i<= sqrt(n); i+=2)
    {
        j=0;
        while(n%i == 0)
        {
            //a[j] = i;
            n = n/i;
            j++;
        }
        if(j == 0)
            continue;
        printf("%lld^%lld ", i, j);
    }
    if(n > 2)
        printf("%lld^1 ", n);
        //a[j] = n;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    ll n;
    while(1)
    {
        scanf("%lld", &n);
        if(n == 0)
            break;
        else
            prime(n);
        printf("\n");
    }
    return 0;
}