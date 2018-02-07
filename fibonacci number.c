#include<stdio.h>
int main()
{
    long n;
    scanf("%ld",&n);
    long a[n+1],i;
    a[0] = 0;
    a[1] = 1;
    for(i=2;i<=n;i++)
        a[i] = a[i-1] + a[i-2];
    printf("%ld\n",a[n]);
return 0;
}
