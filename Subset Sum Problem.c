#include<stdio.h>
int SubsetSum(int input[],long sum,long n)
{
    int a[n+1][sum+1],i,j;
    for(i=1;i<=sum;i++)
        a[0][i]=0;
    for(i=0;i<=n;i++)
        a[i][0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=sum;j++)
        {
            if( j>=input[i-1] )
                a[i][j] = (a[i-1][j] || a[i-1][j-input[i-1]]);
            else a[i][j] = a[i-1][j];
        }
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=sum;j++)
        {
           printf("%d ",a[i][j]);
        }
        printf("\n");
    }
return a[n][sum];
}
int main()
{
   int input[]={2,3,7,8,10};
   long sum=9,n;
   n=sizeof(input)/sizeof(input[0]);
   if(SubsetSum(input,sum,n))
    printf("yes");
   else printf("no");
return 0;
}
