#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define ll unsigned long long int
#define NUM_BITS_INT 32

using namespace std;
int a[100006]={0};

int main()
{   
    int x, i, j;

    cin>>x;

    for(i=1; i<=x; i++)
        cin>>a[i];

    map<int, int> m, n;
    map<int, int>::iterator it, it2;

    for(i=1; i<=x; i+=2)
    {
        m.insert(make_pair(a[i], a[i+1]));
    }

    n.insert(make_pair(a[1], a[2]));
    it = m.begin();
    it++;
    //cout<<it->first<<" "<<it->second<<endl;

    for(it2 = n.begin(); (it != m.end()) && (it2 != m.end()); it++)
    {    
        if(it->first <= it2->second && it->second <= it2->second)
        {
            n.insert(make_pair(it2->first, it2->second));
        }

        else if(it->first <= it2->second && it->second > it2->second)
        {
            x = it2->first;
            n.erase((it2->first));
            n.insert(make_pair(x, it->second));
        }

        else if(it->first > it2->second)
        {
            n.insert(make_pair(it->first, it->second));
            ++it2;
        }
    }
        
    for(it2 = n.begin(); it2 != n.end(); it2++)
        cout<<it2->first<<" "<<it2->second<<endl;
    
    return 0;
}