#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll unsigned long long int
#define NUM_BITS_INT 32

using namespace std;

int main()
{
    int n, ones=0, bits=0, i=0, ans=0, t;

    cin>>n;

    t=n;
    while(t>0)
    {
        if(t%2 == 1)
            ones++;
        t = t/2;
        bits++;
    }

    if(ones == 1)
    {
        cout<<(1LL << bits)<<endl;
        return 0;
    }

    while(i < ones-1)
    {
        ans += (1LL << i);
        i++;
    }

    ans += (1LL << bits);
    cout<<ans<<endl;
    return 0;
}