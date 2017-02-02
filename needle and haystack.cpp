#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int min_hours(int n, int x, int y)
{
    if(n < 0)
        return 1e8;

    if(n == 0)
        return 1;

    return 1 + min(min_hours(n-x, x, y), min_hours(n-y, x, y));
}

int main()
{   
    int i, j, l, m, flag=0;
    string haystack, needle, s;

    cin>>haystack>>needle;

    l = haystack.size();
    m = needle.size();
    
    if(needle == " " || haystack == " ")
        return -1;
    
    for(i=0; i<l-m+1; i++)
    {
        for(j=i; j<m+i; j++)
            s.push_back(haystack[j]);
        //cout<<s<<endl;

        if(s == needle)
        {
            cout<<"FOUND"<<endl;
            flag=1;
            break;
        }
        s.clear();
    }
    if(!flag)
        cout<<"NOT FOUND"<<endl;

    return 0;
}