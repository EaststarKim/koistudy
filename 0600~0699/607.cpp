#include <stdio.h>   
#include <math.h>   
int a[31]={0,1};   
int main()   
{   
    int i,j,n,m=0,k=1;   
    scanf("%d",&n);   
    for(i=2;i<=n;++i)   
    {   
        a[i]=1100000000;   
        for(j=1;j<i;++j)   
        {   
            k=(int)pow(2,j)-1;   
            k+=2*a[i-j];   
            if(a[i]>k)a[i]=k;   
        }   
    }   
    printf("%d",a[n]);   
    return 0;   
} 