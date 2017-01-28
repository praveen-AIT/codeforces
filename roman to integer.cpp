#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int get_value(char c)
{
    if(c == 'M')
        return 1000;
    else if(c == 'D')
        return 500;
    else if(c == 'C')
        return 100;
    else if(c == 'L')
        return 50;
    else if(c == 'X')
        return 10;
    else if(c == 'V')
        return 5;
    else 
        return 1;
}

int main()
{   
    int i, n, ans=0, p, r, res=0, j=0;
    string s;

    cin>>s;
    res = get_value(s[s.length()-1]);

    for(i=s.length()-2; i>=0; i--)
    {
        p = get_value(s[i]);

        if(p < get_value(s[i+1]))
        {
            res = res - get_value(s[i]);
        }

        else
        {
            ans =  ans + get_value(s[i]);
        }
    }

    cout<<ans + res<<endl;
    return 0;
}
