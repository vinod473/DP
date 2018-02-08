#include<stdio.h>
#include<string.h>
long max(long a,long b)
{
    return  (a<b?b:a);
}
long LongestCommon(char c1[],char c2[])
{
    long l1,l2;
    l1 = strlen(c1);
    l2 = strlen(c2);
    long a[l1+1][l2+1],i,j;
    for(i=0;i<=l1;i++)
    {
        for(j=0;j<=l2;j++)
        {
            if( i==0||j==0 )
                a[i][j] = 0;
            else if( c2[i-1] == c1[j-1] )
                a[i][j] = 1 + a[i-1][j-1];
            else
                a[i][j] = max(a[i-1][j],a[i][j-1]);

        }
    }
     for(i=0;i<=l1;i++)
    {
        for(j=0;j<=l2;j++)
        {
            printf("%ld ",a[i][j]);

        }
                    printf("\n");
    }
return a[l1][l2];
}
int main()
{
  char c1[]="abcdff",c2[]="acbc";
  printf("%ld",LongestCommon(c1,c2));
return 0;
}
