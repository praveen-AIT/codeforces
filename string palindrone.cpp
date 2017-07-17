#include <bits/stdc++.h>

using namespace std;   

int main()
{
    int n, i, j;

    string s;

    int cnt_req=0, k=0, cnt=0;
    cin>>n>>k>>s;
    
    for(i=0; i<n/2; i++)
        if(s[i] != s[n-1-i])
            cnt_req++;

    if(cnt_req > k)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    
    if(n == 1)
    {
        cout<<"9"<<endl;
        return 0;
    }

    for(i=0; i<n/2; i++)
    {
        if(s[i] == s[n-1-i] && s[i] != '9' && k - cnt >= 2)
        {
            s[i] = s[n-1-i] = '9';
            cnt += 2;
            continue;
        }

        if(s[i] != s[n-1-i] && s[i] != '9' && s[n-1-i] != '9' && k - cnt >= 1)
        {
            if(k - cnt >= 2)
                s[i] = '9', s[n-1-i] = '9', cnt += 2;
            else
            {
                cnt++;
                int temp = max(s[i], s[n-1-i]);
                if(temp == s[i])
                    s[n-1-i] = temp;
                else
                    s[i] = temp;
            }
            continue;
        }

        if(s[i] != s[n-1-i] && (s[i] != '9' || s[n-1-i] != '9') && k - cnt >= 1)
        {
            if(s[i] != '9')
                s[i] = '9';
            else
                s[n-1-i] = '9';
            cnt++;
            continue;
        }
    }

    if(n%2 != 0 && k-cnt > 0)
        s[n/2] = '9';

    cout<<s<<endl;
}