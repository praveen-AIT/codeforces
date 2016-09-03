#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m, i, j;
    string a[3002], b[3002], c;

    cin>>n>>m;

    for(i=1; i<=m; i++)
    {
        cin>>a[i]>>b[i];
    }

    for(i=1; i<=n; i++)
    {
        cin>>c;
        for(j=1; j<=m; j++)
        {
            if(a[j] == c)
            {
                if(a[j].length() > b[j].length())
                    cout<<" "<<b[j];
                else
                    cout<<" "<<a[j];
            }
        }
    }
    cout<<endl;
    return 0;
}