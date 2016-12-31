#include <stdio.h>
#include <stdlib.h>
#include <iostream>
 
using namespace std;
 

int main(void)
{
    int n, d=0, dist;
    string s;

    cin>>n;
    while(n--)
    {
        cin>>dist>>s;
        
        if(d <= 0 && s != "South" || (d >= 20000 && s != "North") || n == 0 && s != "North")
        {
            cout<<"NO"<<endl;
            return 0;
        }

        if(s == "South")
            d += dist;
        if(s == "North")
            d -= dist;

        if(d > 20000 || d < 0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }

    if(d <= 0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return (0);
}