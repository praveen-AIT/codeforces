#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i=0, j=1;

    cin>>n;
    
    for(i=1; i<=n; i+=2)
    {
        if(i == n && (n%2 != 0))
        {
            if(j%2 != 0)
                cout<<"a"<<endl;
            else
                cout<<"b"<<endl;
            break;
        }
        if(j%2 != 0)
            cout<<"aa";
        else
            cout<<"bb";
        j++;
    }

    return 0;
}