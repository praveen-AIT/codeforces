int main()
{   
    int n, i, ans=0, x=1;

    cin>>n;
    int a[n+2], b[n+2]={0};

    for(i=0; i<n; i++)
        cin>>a[i];

    for(i=0; i<n; i++)
        b[i] = 1;

    for(i=1; i<n; i++)
    {
        if(a[i] > a[i-1])
            b[i]=b[i-1]+1;
    }

    for(i=n-2; i>=0; i--)
    {
        if(a[i] > a[i+1] && b[i] < b[i+1] + 1)
            b[i] = b[i+1] + 1;
    }

    for(i=0; i<n; i++)
    {
        ans += b[i];
        cout<<b[i]<<" ";
    }

    cout<<ans<<endl;
    return 0;
}