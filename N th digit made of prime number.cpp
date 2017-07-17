#include <bits/stdc++.h>
  
using namespace std;   

int main()
{
    int t;

    cin>>t;

    while(t--)
    {
        int n, i = 2, ans=0, x = 0;

        cin>>n;

        while(x != n)
        {
            int temp = i, found = 0;

            while(temp > 0)
            {
                int s = temp % 10;
                temp = temp / 10;

                if(s == 2 || s == 3 || s == 5 || s == 7)
                    found = 1;
                else
                {
                    found = 0;
                    break;
                }
            }

            if(found)
                x++;
            i++;
        }

        cout<<i-1<<endl;
    }

}