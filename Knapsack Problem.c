#include<stdio.h>

int max(int a,int b)
{
    return (a>b?a:b);
}
int Knapsack(int val[],int wt[],int w,int n)
{
    int k[n+1][w+1],i,j;
    for( i=0 ; i<=n ; i++ )
    {
        for( j=0 ;j<=w ; j++ )
        {
            if( i==0 ||  j==0 )
                k[i][j]=0;
            else if( wt[i-1] <= j )
                k[i][j] = max(val[i-1]+k[i-1][j-wt[i-1]],k[i-1][j]);
            else k[i][j] = k[i-1][j];
        }
    }
return k[n][w];
}
int main()
{
    int w=7,i,n;
    int val[]={1,4,5,7},wt[]={1,3,4,5};
    n=sizeof(val)/sizeof(val[0]);
    printf("%d",Knapsack(val,wt,w,n));
return 0;
}
