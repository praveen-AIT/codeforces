#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans=0, cur=0, i;
    string s;

    cin>>s;

    for(i = s.size()-1; i>=0; i--)
    {
        if(s[i] == 'b')
            cur = (cur + 1)%(1000000007);
        else
            ans = (ans + cur)%(1000000007), cur = (cur * 2)%(1000000007);
    }

    cout<<ans<<endl;

    return 0;
}