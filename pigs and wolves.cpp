#include <bits/stdc++.h>
 
using namespace std;   

int main()
{
    int n, m, i, j, ans=0;
    char ch[50][50];

    cin>>n>>m;

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            ch[i][j] = '.';
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            cin>>ch[i][j];
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(ch[i][j] == 'P')
            {
                if(ch[i+1][j] == 'W' || ch[i-1][j] == 'W' || 
                   ch[i][j+1] == 'W' || ch[i][j-1] == 'W')
                    ans++;

                if(ch[i+1][j] == 'W')
                    ch[i+1][j] = '.';
                if(ch[i-1][j] == 'W')
                    ch[i-1][j] = '.';
                if(ch[i][j+1] == 'W')
                    ch[i][j+1] = '.';
                if(ch[i][j-1] == 'W')
                    ch[i][j-1] = '.';
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}