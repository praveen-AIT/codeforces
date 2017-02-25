#include <bits/stdc++.h>
using namespace std;
 
void countDistinct(int arr[], int n, int k)
{
    map<int, int> hash;
    map<int, int> :: iterator it;

    for(int i=0; i<n; i++)
    {
        hash[arr[i]]++;
        
        if(i >= 3)
        {
            if(i > 3)
                --hash[arr[i-4]];
            if(hash[arr[i-4]] == 0)
                hash.erase(arr[i-4]);
            cout<<hash.size()<<endl;
        }
    }
}
 
int main()
{
    int arr[] = {1, 3, 2, 5, 5, 2, 2, 6},  k = 4;
    int n = sizeof(arr)/sizeof(arr[0]);
    countDistinct(arr, n, k);
    cout<<endl;
    return 0;
}