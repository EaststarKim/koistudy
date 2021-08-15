#include <stdio.h>
int n,a[262145];
void back(int s,int e)
{
    int i,j,z=0,o=0,m,k;
    if(s==e)
    {
        printf("%d",a[s]);
        return;
    }
    for(i=s;i<=e;++i)
    {
        if(!a[i])z=1;
        else o=1;
        if(z&&o)break;
    }
    if(z&&o)
    {
        printf("-");
        m=(s+e)/2;
        back(s,m);
        back(m+1,e);
        return;
    }
    if(z)
    {
        printf("0");
        return;
    }
    printf("1");
    return;
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%1d",a+i);
    back(1,n);
    return 0;
}
