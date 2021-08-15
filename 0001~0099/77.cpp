#include <stdio.h>
int main()
{
    int i,n,s=0;
    scanf("%d",&n);
    for(i=2;i<=n;i+=2)s+=i;
    printf("%d",s);
}
