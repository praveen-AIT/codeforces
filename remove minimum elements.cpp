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
    int n, i, j, fans = INT_MAX, ans = 0;

    cin>>n;
    int a[n+10] = {0};

    for(i=0; i<n; i++)
        cin>>a[i];

    for(i=0; i<n; i++)
    {
        ans = 0;
        for(j=0; j<i; j++)   
        {
            if(a[j] > 2*a[i])
                ans++;
            else
                break;
        }

        for(j=n-1; j > i; j--)
        {
            if(a[j] > 2*a[i])
                ans++;
            else
                break;   
        }
        cout<<ans<<endl;    
        fans = min(fans, ans);
    }

    cout<<fans<<endl;
    return 0;    
}