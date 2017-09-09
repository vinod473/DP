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
    long a[l2+1][l1+1],i,j;
    for(j=0;j<=l1;j++)
        a[0][j]=0;
    for(j=0;j<=l2;j++)
        a[j][0]=0;
    for(i=1;i<=l2;i++)
    {
        for(j=1;j<=l1;j++)
        {
            if( c2[i-1] != c1[j-1] )
                a[i][j] = max(a[i-1][j],a[i][j-1]);
            else
                a[i][j] = 1+a[i-1][j];
        }
    }
return a[l2][l1];
}
int main()
{
  char c1[]="abcdaf",c2[]="acbcf";
  printf("%ld",LongestCommon(c1,c2));
return 0;
}
