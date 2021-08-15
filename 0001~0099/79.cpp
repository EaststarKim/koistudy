#include <stdio.h>
int main()
{
    int i,s=0,k;
    scanf("%d",&k);
    for(i=1;s<k;++i)s+=i;
    printf("%d",i-1);
}
