#include <bits/stdc++.h>
using namespace std;
 
bool distance(int arr[], int n, int k)
{
    map<int, vector<int> > hash;
    map<int, vector<int> > :: iterator it;

    int flag=0;

    for(int i=0; i<n; i++)
    {
        if(hash.count(arr[i]) == 0)
            hash[arr[i]].push_back(i);
        else
            if(abs(hash[arr[i]][0] - i) <= k)
                hash[arr[i]].push_back(i), flag=1;
    }

    it = hash.begin();
    for(int i=0; i<hash.size(); i++)
    {
        for(int j=0; j<hash[i].size(); j++)
            cout<<" "<<hash[i][j]<<" ";
        cout<<endl;
        ++it;
    }

    if(flag)
        return true;
    return false;
}
 
int main()
{
    int arr[] =  {1, 2, 3, 1, 5};
    int k = 6;
    int n = sizeof(arr)/sizeof(arr[0]);
    distance(arr, n, 3)? cout << "True": cout << "False";
    cout<<endl;
    return 0;
}