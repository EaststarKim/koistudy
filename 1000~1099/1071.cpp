#include <stdio.h>
int main()
{
    int i,t,n,l,r,s=0;
    scanf("%d%d%d",&n,&l,&r);
    for(i=1,t=1;t<=r;--i,t*=2)s+=i*((r+t)/t/2-(l-1+t)/t/2);
    printf("%d",s);
    return 0;
}
