#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int minn(int a, int b, int c)
{
    return min(a, min(b, c));
}

int ugly_numbers(int n, int ans, int i)
{
    int ug[n], i2=0, i3=0, i5=0;
    int m2 = 2, m3 = 3, m5 = 5;
    ug[0] = 1;

    for(i=1; i<n; i++)
    {
        ug[i] = minn(m2, m3, m5);

        if(ug[i] == m2)
        {
            i2++;
            m2 = ug[i2]*2;
        }
        if(ug[i] == m3)
        {
            i3++;
            m3 = ug[i3]*3;
        }
        if(ug[i] == m5)
        {
            i5++;
            m5 = ug[i5]*5;
        }
    }
    return ug[n-1];
}

int main()
{   
    int n, ans;

    cin>>n;

    ans = ugly_numbers(n, 0, 1);
    cout<<ans<<endl;

    return 0;
}
