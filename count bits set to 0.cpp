#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll unsigned long long int
#define NUM_BITS_INT 32

using namespace std;

int main()
{
    int temp, n, bit, i = 0, zeroes=0;
 
    printf("Enter a number : ");
    scanf("%d", &n);
    temp = n;
    
    while(i < NUM_BITS_INT)
    {
        if(!(temp & 1))
            zeroes++;
        temp >>= 1;
        i++;
    }

    cout<<zeroes<<endl;
    return 0;
}