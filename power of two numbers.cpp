int main()
{   
    int n, i, j, flag=0;

    cin>>n;

    if (n==1)  return true;
 
    // Try all numbers from 2 to sqrt(n) as base
    for (int x=2; x<=sqrt(n); x++)
    {
        unsigned y = 2;
        unsigned p = pow(x, y);
 
        // Keep increasing y while power 'p' is smaller
        // than n. 
        while (p<=n && p>0)
        {
            if (p==n)
            {
                cout<<"YES"<<endl;
                break;
            }
            y++;
            p = pow(x, y);
         }
    }
    return 0;
}