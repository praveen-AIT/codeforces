#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, ans=0, i, j, mx = INT_MIN, x;

    cin>>n;
    int a[1002] = {0};

    for(i=1; i<=n; i++)
    {
        cin>>x;
        ++a[x];
        if(a[x] > mx)
            mx = a[x];
    }
    //cout<<mx<<endl;
    while(mx--)
    {
        int cnt=0;
        for(i=1; i<1002; i++)
        {
            if(a[i] > 0)
            {
                if(cnt>0)
                    ++ans;
                --a[i];
                cnt++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}