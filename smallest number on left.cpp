#include <bits/stdc++.h>
using namespace std;

int modular(int base, unsigned int exp, unsigned int mod)
{
    int x = 1, power;

    power = base % mod;
    for(int i=0; i < 32; i++)
    {
        int lsb = 0x000000001 & (exp >> i);

        if(lsb)
            x = (x*power)%mod;

        power = (power * power)%mod;
    }
    return x;
}

int main(void) 
{
    int n, i, t;

    cin>>t;

    while(t--)
    {
        int a[200], found = 0;
        cin>>n;

        for(i=0; i<n; i++)
            cin>>a[i];

        cout<<"-1 ";

        for(i=1; i<n; i++)
        {
            found = 0;
            for(int j=i-1; j>=0; j--)
            {
                if(a[j] < a[i])
                {
                    found = 1;
                    cout<<a[j]<<" ";
                    break;
                }
            }

            if(!found)
                cout<<"-1 ";
        }
    }

    return 0;    
}