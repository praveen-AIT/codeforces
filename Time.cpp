#include <bits/stdc++.h>
    
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(0);
    //ostringstream ss;
    string s;
    int n, i, h1, h2, m1, m2;

    cin>>s>>n;

    h1 = int(s[0]) - '0';
    h1 = 10*h1 + (int(s[1] - '0'));

    m1 = int(s[3]) - '0';
    m1 = 10*m1 + (int(s[4] - '0'));
    
    h2 = n/60;
    m2 = n%60;

    m1 = m1 + m2;
    if(m1 >= 60)
    {
        m1 = m1 % 60;
        h1++;
    }

    h1 = h1 + h2;
    if(h1 >= 24)
    {
        h1 = h1 % 24;
    }
    if(m1 < 10)
    {
        if(h1 < 10)
        {
            cout<<"0"<<h1<<":0"<<m1<<endl;
            return 0;
        }
        cout<<h1<<":0"<<m1<<endl;
        return 0;
    }
    if(h1 < 10)
    {
        cout<<"0"<<h1<<":"<<m1<<endl;
        return 0;
    }
    cout<<h1<<":"<<m1<<endl;
    return 0;
}
