#include <bits/stdc++.h>
#define ll long long
using namespace std;

int b;

int main()
{
    ios_base::sync_with_stdio(0);
    int a, temp, x, y, z, ans=0, temp2, temp3, sum=0;

    cin>>a>>b;
    x = b, y = b, z = b;
    sum = 3*b;
    while(x != a || y != a || z != a)
    {
        temp = min(x, min(y, z));
        temp2 = max(x, max(y, z));
        temp3 = sum - (temp + temp2);
        z = temp2 + temp3 - 1;
        x = temp3;
        y = temp2;
        if(z > a)
            z = a;
        if(x > a)
            x = a;
        if(y > a)
            y = a;
        sum = x + y + z;
        ans++;
        //cout<<x<<" "<<y<<" "<<z<<endl;
    }
    cout<<ans<<endl;    
    return 0;
}