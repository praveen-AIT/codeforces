#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int steps(int p, int x, int y, int step, int pos)
{
    if(pos > p)
        return 0;

    if(pos == p)
        return step;

    else
        return min(
                   steps(p, x, y, step+1, pos + pow(x, step)), 
                   steps(p, x, y, step+1, pos + pow(y, step))
                  );
}

int main()
{   
    vector <string> a;
    int i, n, j;
    string ans, s;
    
    for(i=0; i<3; i++)
    {
        cin>>s;
        a.push_back(s);
    }

    ans = a[0];

    for(i=1; i<a.size(); i++)
    {
        s = a[i];
        for(j=0; j<ans.length(); j++)
        {
            if(s[j] != ans[j])
            {
                ans.erase(ans.begin()+j, ans.end());
                break;
                //--j;
            }

        }
    }
    cout<<ans<<endl;
    return 0;
}
