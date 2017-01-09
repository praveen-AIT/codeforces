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
    int temp, n, bit, i = 0;
 
    printf("Enter a number : ");
    scanf("%d", &n);
    temp = n;
    
    while(i < NUM_BITS_INT)
    {
        bit = temp & 0x80000000;
        if(bit == 0x80000000)
        {
            bit = 1;
        }
        printf("%d", bit);

        temp = temp << 1;
        i++;
    }

    cout<<endl;
    return 0;
}