#include <stdio.h>   
int a[80001];   
long long int s,p;   
int main()   
{   
    int i,n,k;   
    scanf("%d",&n);   
    for(i=1;i<=n;++i)   
    {   
        scanf("%d",&k);   
        while(p>0&&a[p-1]<=k)   
        {   
            --p;   
            s+=p;   
        }   
        a[p++]=k;   
    }   
    s+=p*(p-1)/2;   
    printf("%lld",s);   
    return 0;   
}