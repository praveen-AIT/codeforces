#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int a[500000], id;

int checkprime(int n)
{
    int i;
    
    if(n == 2)
        return 1;
    while(n%2 == 0)
    {
        n = n/2;
        return -1;
    }

    for(i=3; i<=sqrt(n); i++)
    {
        while(n%i == 0)
        {
            n = n/i;
            return -1;
        }
        
    }
    return 1;
}
int main()
{   
    int n ,ans, i=0, j=0, k, pm=0;

    cin>>n;

    for(i=n-2; i>=n/2; i--)
    {
        k = checkprime(i);
        if(k == 1)
        {
            k = checkprime(n-i);
            j = i;
            if(k == 1)
            {
                ans = n-i;
                break;
            }
        }
    }    
    cout<<ans<<" "<<j<<endl;
    return 0;
}