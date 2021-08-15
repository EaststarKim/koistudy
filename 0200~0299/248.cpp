#include <stdio.h>   
int a[2][30010],mn=30001;   
int main()   
{   
    int n,i,k,s;   
    scanf("%d",&n);   
    for(i=1;i<=n;++i)   
    {   
        scanf("%d",&k);   
        a[0][i]=a[0][i-1]+(k%2);   
        a[1][i]=a[1][i-1]+(k/2);   
    }   
    for(i=0;i<=n;++i)   
    {   
        s=a[1][i]+a[0][n]-a[0][i];   
        if(mn>s)mn=s;   
    }   
    printf("%d",mn);   
    return 0;   
}  