#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, i, j;
    char ch;
    cin>>n>>m;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            cin>>ch;
            if(ch == 'C' || ch == 'M' || ch == 'Y')
            {
                printf("#Color\n");
                return 0;
            }
        }
    }
    printf("#Black&White\n");
    return 0;
}