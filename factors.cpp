vector<int> Solution::allFactors(int A) 
{
    int i;
    vector <int> ans;
    
    for(i=1; i<=sqrt(A); i++)
    {
        if(A%i == 0)
        {    
            ans.push_back(i);
            if(i != A/i)
                ans.push_back(A/i);
        }
    }
            
    //ans.push_back(A);
    sort(ans.begin(), ans.end());
    return ans;
}
