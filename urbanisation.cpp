#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    int a, b, c, e, f, i, j, temp, temp1, cnt=0;
    float x=0, y=0, ans;

    cin>>a>>b>>c;
    int p[a+50];
    for(i=0; i<a; i++)
    {
        cin>>p[i];
    }

    sort(p, p+a);
    temp = max(b, c);
    temp1 = min(b, c);

    e = temp;
    f = temp1;
    b = e;
    c = f;

    for(j=a-1; j>=0; j--)
    {
        if(f>0)
        {
            f--;
            x += p[j];
        }
        else if(e>0 && f<=0)
        {
            e--;
            y += p[j];
        }
        cnt++;
    }

    cout<<fixed;
    cout<<(x/c + y/b)<<setprecision(6)<<endl;
    return 0;
}