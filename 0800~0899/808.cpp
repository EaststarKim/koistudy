#include <stdio.h>
#include <algorithm>
int a[30010],s;
int main()
{
    int i,n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;++i)scanf("%d",&a[i]),s+=a[i];
    std::sort(&a[1],&a[n+1]);
    for(i=n;i>n-k&&i>0;--i)s-=a[i];
    printf("%d\n",s);
    if(s<=m)printf("Safe");
    else
    {
        printf("TS\n");
        for(;s>m;--i)s-=a[i];
        printf("%d",n-k-i);
    }
    return 0;
}
