#include <bits/stdc++.h>
using namespace std;

 
int main()
{
    int a, b, i;

    cin>>a>>b;

    for(i=0; i<=100000000; i++)
    {
        if(i%2==0)
        {
            b -= i;
            if(b<0)
            {
                cout<<"Valera"<<endl;
                return 0;
            }

            cout<<"B "<<b<<endl;
        }

        else
        {
            a -= i;
            if(a < 0)
            {
                cout<<"Vladik"<<endl;
                return 0;
            }
            cout<<"A "<<a<<endl;
        }
    }
    return 0;
}