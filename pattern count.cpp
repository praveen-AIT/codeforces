#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, cont = 0, ans = 0, q;
    string s;

    cin>>q;

    for(int j=0; j<q; j++)
    {
        int ans = 0, cont = 0, zero = 0;;
        cin>>s;
        for(i=0; i<s.length(); i++)
        {
            if(!cont && s[i] == '1')
            {
                cont = 1;
                continue;
            }

            if(cont && (s[i] == '1' || s[i] == '0'))
            {
                if(s[i] == '1' && zero)
                    ans++, zero = 0;
                else if(s[i] == '0')
                    zero = 1;
            }
            else
                cont = 0;
        }
        cout<<ans<<endl;    
    }
    return 0;
}