#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string s;
    int n, i;
    cin>>s;
    n = s.length();
    for(i=0; i<n; i++)
    {
        if(s[i] == '.')
        {
            cout<<"0";
        }   
        else
        {
            if(s[i] == '-' && s[i+1] == '.')
            {
                cout<<"1";
                i++;
            }
            else if(s[i] == '-' && s[i+1] == '-')
            {
                cout<<"2";
                i++;
            }
        }
    }
    cout<<endl;
    return 0;
}

