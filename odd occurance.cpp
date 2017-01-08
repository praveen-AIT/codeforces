#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll unsigned long long int

using namespace std;

int fun()
{
    static int num=32;
    return num--;
}

int main(void)
{
    
    int n, t, ans=0, i, a[1006]={0}, x;

    cin>>t;
    while(t--)
    {
        int a[1006]={0};
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>x;
            a[x]++;
        }
        for(i=1; i<1005; i++)
            if(a[i]%2 != 0)
                cout<<i<<endl;
    }
    return (0);
}