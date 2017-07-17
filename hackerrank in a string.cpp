#include <bits/stdc++.h>

using namespace std;   

int main()
{
    int n, i, ans=0, q, j=0;
    string s;

    string ch = "hackerrank";
    cin>>q;

    for(int k=0; k<q; k++)
    {
        ans = 0, j=0;
        for(i=0; i<s.length(); i++)
        {
            if(s[i] == ch[j++])
                ans++;
        }

        if(ans)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}