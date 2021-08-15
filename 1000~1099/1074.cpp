#include <stdio.h>
int a[500010],s,ans,f,r;
int main()
{
    int i,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    while(r<n){
        s+=a[++r];
        while(s>=m)s-=a[++f];
        if(ans<s)ans=s;
    }
    printf("%d",ans);
    return 0;
}
