#include <bits/stdc++.h>
using namespace std;

int match(string a, int st, string b)
{
    int l=0;
    for(int i=0; i<a.length(); i++)
    {
        if(a[i] == b[(i+st)%b.length()])
            l++;
    }

    if(l == a.length())
        return 1;
    return 0;
}

int main()
{
    int n, i, ans=0, sol=INT_MAX, tmp=0;
    string x;

    cin>>n;

    vector<string> s;
    vector<int> c;

    for(i=0; i<n; i++)
    {
        cin>>x;
        s.push_back(x);
    }

    if(n == 1)
    {
        cout<<"0"<<endl;
        return 0;
    }

    for(i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(s[i] == s[j] || i == j)
                continue;

            for(int k=0; k<s[j].length(); k++)
            {
                ans = match(s[i], k, s[j]);
                if(ans)
                {
                    tmp += k;
                    break;
                }
            }
            
            if(!ans)
            {
                cout<<"-1"<<endl;
                return 0;
            }       
        }

        c.push_back(tmp);
        tmp = 0;
    }

    for(i=0; i<c.size(); i++)
        sol = min(sol, c[i]);
    cout<<sol<<endl;

    return 0;
}