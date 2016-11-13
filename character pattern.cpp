#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, r, c, i, j;
    string s;

    cin>>t;
    while(t--)
    {
        cin>>r>>c;
        
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(i%2 == 0 )
                {
                    if(j%2 == 0)
                        cout<<"*";
                    else
                        cout<<".";
                }
                else
                {   
                    if(j%2 == 0)
                        cout<<".";
                    else
                        cout<<"*";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}