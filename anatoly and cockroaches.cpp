#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, i, j, r=0, b=0, ans, e=0, o=0;
    string s;
    char p, q;
    cin>>n;
    cin>>s;
    //cout<<p<<" "<<q<<endl;
    for(i=0; i<n; i++)
    {
        if(i%2 == 0 && s[i] == 'b')
        {
            e++;
        }
        else if(i%2 != 0 && s[i] == 'b')
        {
            o++;
        }
    }

    if(e == o)
    {
        e = 0, o = 0;
        for(i=0; i<n; i++)
        {
            if(i%2 == 0 && s[i] == 'r')
            {
                e++;
            }
            else if(i%2 != 0 && s[i] == 'r')
            {
                o++;
            }
        }
        //cout<<e<<" "<<o<<endl;
        if(e > o)
            p = 'r', q = 'b';
        else
            p = 'b', q = 'r';   
    }
    else
    {
        if(e > o)
            p = 'b', q = 'r';
        else
            p = 'r', q = 'b';
    }

    for(i=0; i<n; i++)
    {
        if(i%2 == 0)
        {
            if(s[i] != p)
                b++;
        }
        else
        {
            if(s[i] != q)
                r++;
        }
    }
    //cout<<b<<" "<<r<<endl;
    ans = min(b, r) + abs(b-r);
    cout<<ans<<endl;
    return 0;
}