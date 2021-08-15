#include <stdio.h>
int main()
{
    int n,k;
    scanf("%d",&n);
    aa:
    scanf("%d",&k);
    printf("%d\n",k);
    if(--n)goto aa;
}
