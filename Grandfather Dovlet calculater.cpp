#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, ans=0, i, j, x;

    int c[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    cin>>a>>b;
    for(i=a; i<=b; i++)
    {
        int temp = i;
        while(temp > 0)
        {
            x = temp%10;
            temp = temp/10;
            ans += c[x]; 
        }
    }
    cout<<ans<<endl;
    return 0;
}