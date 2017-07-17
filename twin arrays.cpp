#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, x;
    vector <pair <int, int> > a, b;

    cin>>n;

    for(i=0; i<n; i++)
    {
        cin>>x;
        a.push_back(make_pair(x, i));
    }

    for(i=0; i<n; i++)
    {
        cin>>x;
        b.push_back(make_pair(x, i));
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    
    for(i=0; i<n; i++)
    {
        if(a[i].second != b[i].second)
        {
            cout<<(a[i].first + b[i].first)<<endl;
            break; 
        }
        else
        {
            int ans = min(a[i].first + b[i+1].first, a[i+1].first + b[i].first);
            cout<<ans<<endl;
            break;
        }
    }
    return 0;
}