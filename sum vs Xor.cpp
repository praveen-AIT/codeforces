#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll unsigned long long int

using namespace std;

int main(void)
{
    ll n, i=0, j, flag=0, a[200]={0}, t, zeroes=0;

    cin>>t;

    if(t == 0)
    {
        cout<<"0"<<endl;
        return 0;
    }

    while(t > 0)
    {
        a[i] = t%2;
        t = t/2;
        i++;
    }

    i -= 1;

    for(j=0; j<=i; j++)
        if(a[j] == 0)
            zeroes++;

    cout<<(1LL << zeroes)<<endl;

    return (0);
}