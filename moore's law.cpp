#include <bits/stdc++.h>
#include <string>  

using namespace std;
int main() 
{
    ios_base::sync_with_stdio(0);
    //ostringstream ss;
    double n, t, ans, x = 1.000000011;
    cin>>n>>t;
    //ans = (n+(t*x));
    //ss<<ans;
    //string s = ss.str();
    cout<<fixed<<setprecision(7) <<(n*pow(x, t))<< '\n';

    return 0;
}