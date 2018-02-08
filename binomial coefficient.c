#include<stdio.h>
long binomial(int n,int k)
{
    int dp[n+1][k+1],i,j;
    for(i=0;i<=n;i++)
    {
      for(j=0;j<=k;j++)
        {
          if( j==0 || i==j )
            dp[i][j] = 1;
        else if(i>j)
            dp[i][j] = dp[i-1][j-1] +dp[i-1][j];
        }
    }
    return dp[n][k];
}
int main()
{
    int n,k;
    scanf("%ld%ld",&n,&k);
    printf("%ld\n",binomial(n,k));
return 0;
}
