#include <bits/stdc++.h>
   
using namespace std;

int main()
{
    int t, i;

    cin>>t;

    while(t--)
    {
        int n, i, ans = INT_MIN, curr_sum;
        cin>>n;

        int a[n+10];
        for(i=0; i<n; i++)
            cin>>a[i];

        for(i=0; i<n; i++)
        {
            curr_sum = a[i];

            while(i+1 < n && a[i] < a[i+1])
            {
                curr_sum += a[i+1];
                i++;
            }
            if(curr_sum > ans)
                ans = curr_sum;
        }
        
        cout<<ans<<endl;
    }

}
