#include <bits/stdc++.h>
#define ll unsigned long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m ,k, i, j, a, b, c;

    scanf("%d%d%d", &n, &m, &k);
    
    int x[5005] = {0}, y[5005] = {0}, u[5005], v[5005];

    for(i=1; i<=k; i++)
    {
        scanf("%d%d%d", &a, &b, &c);

        if(a == 1)
        {
            x[b] = c;
            u[b] = i;
        }
        else
        {
            y[b] = c;
            v[b] = i; 
        }
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(y[j] != 0 && v[j] > u[i])
                printf("%d ", y[j]);
            else
                printf("%d ", x[i]);
        }
        printf("\n");
    }
    return 0;
}