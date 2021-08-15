#include <stdio.h>   
int a[1010],s;   
int main()   
{   
    int i,j,n,k;   
    scanf("%d",&n);   
    for(i=1;i<=n;++i)   
    {   
        scanf("%d",&k);   
        ++a[k];   
    }   
    for(i=1;i<1001;++i)   
    {   
        for(j=1000;j>i;--j)s+=(j-i)*a[i]*a[j];   
    }   
    printf("%d",s*2);   
    return 0;   
}  