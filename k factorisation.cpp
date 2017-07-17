#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, i, j=3, tmp;
    long long int prod = 1;
    vector<int> sol;
    
    cin>>n>>k;
    tmp = n;

    for(i=1; i<k; i++)
    {
        if(n%2 == 0)
        {
            n = n/2;
            sol.push_back(2);
            prod *= 2;
            continue;
        }

        for(int j=3; j<=n; j+=2)
        {
            if(n%j == 0)
            {
                sol.push_back(j);
                n = n/j;
                prod *= j;
                break;
            }
        }
    }
    
    if(n != 1)
        sol.push_back(n), prod *= n;
    
    if(prod != tmp || sol.size() != k)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    else
    {
        for(i=0; i<sol.size(); i++)
            cout<<sol[i]<<" ";
    }
    
    cout<<endl;
    return 0;
}