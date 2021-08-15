#include <stdio.h>
int a[30];
int main()
{
    int i,n,k;
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%d",&k),++a[k];
    for(i=1;i<24;++i)printf("%d ",a[i]);
}
