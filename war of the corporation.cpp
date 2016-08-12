#include <bits/stdc++.h>
    
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(0);
    //ostringstream ss;
    int i, j ,ans=0, cnt=0, k;
    string a, b;

    cin>>a>>b;
    if(a.length() < b.length())
    {
        cout<<"0"<<endl;
        return 0;
    }
    k = a.length() - b.length() + 1;
    for(i=0; i<k; i++)
    {
        cnt = 0;
        for(j=0; j<b.length(); j++)
        {
            if(a[i+j] == b[j])
                cnt++;
            if(cnt == b.length())
                ans++, i = i+j;
        }
    }
    cout<<ans<<endl;
    return 0;
}
