#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll unsigned long long int

using namespace std;

int main(void)
{
    ll n, t, k, j, ans=0, i=0, flag=1;

    cin>>t;

    while(t--)
    {
        cin>>n;
        k = n;
        i=0, ans=0;
        while(i < 32)
        {
            j = k%2;
            k = k/2;
            if(j == 0)
            {
                ans += (1LL << i);
            } 
            i++;
        }
        cout<<ans<<endl;
    }

    return (0);
}