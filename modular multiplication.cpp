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
    int a, b, c, t;

    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;

        int ans = modular(a, b, c);
        cout<<ans<<endl;
    }
    return 0;    
}