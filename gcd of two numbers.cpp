int gcd(int a, int b)
{
    // base case
    if (a == b)
        return a;
 
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
 
// Function to return LCM of two numbers
int lcm(int a, int b)
{
    return (a*b)/gcd(a, b);
}

int main()
{   
    int a, b, i;

    cin>>a>>b;

    cout<<gcd(a, b)<<endl;


    return 0;
}