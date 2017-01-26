int main()
{   
    int n, i, p, q, t;
    string a, b;

    cin>>t;

    while(t--)
    {
        cin>>a>>b;
        p = a.length(), q = b.length();
        int cap=0, ans=0, j=0;

        for(i=0; i<p; i++)
            if(a[i] >= 65 && a[i] < 97)
                cap++;

        for(i=0; i<q; i++)
        {
            for(;j<p; j++)
            { 
                if(b[i] == a[j]-32 || b[i] == a[j])
                {                    
                    ans++;
                    --j;
                    break;
                }
                
            }
        }
        //cout<<cap<<" "<<ans<<endl;
        if(ans == q && cap <= q)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}