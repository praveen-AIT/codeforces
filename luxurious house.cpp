#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n, m=INT_MIN, i;
    cin>>n;
    int a[n], maxno[n+2] = {0};

    for(i=1; i<=n; i++)
    {
        cin>>a[i];
    }

    for(i=n; i>0; i--)
    {
        if(a[i] > m)
        {
            m = a[i];
            maxno[i] = a[i]-1;
        }
        else
            maxno[i] = m;
    }
    for(i=1; i<n; i++)
        printf("%d ", abs(maxno[i] - a[i] + 1));
    printf("0\n");
    return 0;
}