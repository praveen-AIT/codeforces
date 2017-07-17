#include <bits/stdc++.h>
 
using namespace std;   

int main()
{
    int n, k, i, t, x;

    cin>>t;

    while(t--)
    {
        int flag = 0;
        
        vector< pair<int, int> >p;
        
        cin>>n;
        
        for(i=0; i<n; i++)
        {
            cin>>x;
            p.push_back(make_pair(x, i));
        }
        
        cin>>k;
        sort(p.begin(), p.end());
        
        for(i=0; i<n; i++)
        {
            if(abs(p[i].second - i) <= k)
                flag=0;
            else
            {
                flag=1;
                break;
            }    
        }

        if(flag)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;

        
    }

}