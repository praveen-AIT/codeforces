#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, i, j;
    long long a[500000], b[500000] = {0};
    double sum = 0, x;

    cin>>n>>k;
    
    for(i=1; i<=n; i++)
    {
        cin>>a[i];
        b[i] = b[i-1] + a[i];
    }

    for(i=k; i <= n; i++)
    {
        sum += b[i] - b[i-k];
    }

    x = (sum/(n-k+1));
    cout<<setprecision(6);
    cout<<fixed;
    cout<<x<<endl;
    return 0;
}