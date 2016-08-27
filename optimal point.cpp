#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, i;
    scanf("%d", &n);
    int a[n];

    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    if(n%2 == 0)
        printf("%d\n", a[n/2-1]);
    else
        printf("%d\n", a[n/2]);
    return 0;
}