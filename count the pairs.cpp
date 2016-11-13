#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    ll n, k, i, j, x, ans=0;
    string s;

    cin>>n>>k;
    ll b[n+5];

    for(i=0; i<n; i++)
    {
        cin>>x;
        b[i]=x;
    }

    sort(b, b+n);

    for(i=0; i<n; i++)
    {
        x = b[i]-k;
        //cout<<x<<endl;
        int st=0, end=n-1;
        while(st <= end)
        {
            int mid=(st+end)/2;
            //cout<<mid;
            if(x == b[mid])
            {
                ans++;
                break;
            }
            else if(x < b[mid])
            {
                end=mid-1;
            }
            else if(x > b[mid])
            {
                st=mid+1;
            }
        }
    }    
    cout<<ans<<endl;
    return 0;
}