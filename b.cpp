# include <bits/stdc++.h>

using namespace std;  

int power(int n)
{
    int ans, i=0, cnt=0;

    if(n%2 != 0)
        return 0;
    while(n > 0)
    {
        n = n/2;
        ans = n;
        if(n%2 == 0 && ans != 1)
            cnt++;
        else if(ans == 1)
        {
            cnt++;
            break;
        }
        else
            return 0;
    }
    return cnt;
}

int main()
{
    int n, x, pairs=0, i, j;
    cin>>n;
    int a[n];

    for(i=1; i<=n; i++)
    {
        cin>>a[i];
        for(j=0; j<i; j++)
        {
            x = a[i]+a[j];
            //cout<<power(x)<<" "<<x<<endl;
            if(power(x))

                pairs++;
        }   
    }
    cout<<pairs<<endl;
    return 0;
}