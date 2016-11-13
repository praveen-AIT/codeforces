#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, l, i;
    string s;

    cin>>t;
    while(t--)
    {
        cin>>s;
        l = s.length();
        for(i=0; i<l/2; i++)
        {
            if(i%2 == 0)
                cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}