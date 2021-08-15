#include <stdio.h>
int main()
{
    int i,n,k,s=0;
    scanf("%d",&n);
    k=n/3;
    if(n%3)++k;
    for(i=(n-1)/2;i>=k;--i)s+=(i*3-n)/2+1;
    printf("%d",s);
    return 0;
}
