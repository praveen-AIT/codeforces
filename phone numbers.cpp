#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, i;

    string s;
    cin>>n;
    cin>>s;
    if(n == 2)
        cout<<s;
    else if(n == 3)
        cout<<s;
    else
    {       
        int x = s.length()/2-1, cnt=0;
        for(i=2; i<s.length(); i+=3)
        {
            ++cnt;
            s.insert(i, "-");
            if(cnt == x)
                break;
        }
        cout<<s<<endl;
    }
    return 0;
}