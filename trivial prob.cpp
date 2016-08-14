#include <bits/stdc++.h>
#define ll unsigned long long

using namespace std;

int factor(int n)
{
    int cnt = 0, i;
    while(n%2 == 0)
        n = n/2;

    while(n%5 == 0)
    {
        n = n/5;
        cnt++;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int i=0, n, ans=0, x=5, a=0, p[100000];
    cin>>n;
    
    while(1)
    {
        if(x%5 == 0)
            a += factor(x);
        x++;
        if(a == n)
            p[i] = x-1, i++ ,ans=1;
        else if(a < n)
            continue;
        else
            break;
    }
    if(ans == 0)
    {
        printf("0\n");
        return 0;
    }
    printf("%d\n", i);
    for(n=0; n<i; n++)
        printf("%d ", p[n]);
    printf("\n");
    return 0;
}