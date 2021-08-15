#include <stdio.h>   
long long int a[411]={1};   
int main()   
{   
    int i,j,n,m;   
    scanf("%d",&n);   
    m=n*(n+1)/2;   
    if(m%2)a[0]=0;   
    m/=2;   
    for(i=1;i<=n;++i)   
    {   
        for(j=m;j>=i;--j)   
        {   
            if(a[j-i])a[j]+=a[j-i];   
        }   
    }   
    printf("%lld",a[m]/2);   
    return 0;   
}  