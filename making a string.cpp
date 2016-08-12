#include <bits/stdc++.h>
    
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(0);
    //ostringstream ss;
    long long n, i, j, ans=0;
    cin>>n;
    long long a[n];
    for(i=0; i<n; i++)
        scanf("%lld", &a[i]);

    sort(a, a+n);
    reverse(a, a+n);

    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[j] == a[i] && a[j] != 0)
                a[j] = a[j]-1;
            
            else
                break;
        }   
    }

    for(i=0; i<n; i++)
        ans += a[i];

    printf("%lld\n", ans);
    return 0;
}
