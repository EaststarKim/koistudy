#include <stdio.h>
int a[10],st[10],ans[20],s,t;
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%1d",a+i);
    for(i=1;i<=n;++i){
        for(;s<n&&st[t]!=i;)st[++t]=a[++s];
        if(st[t]!=i)break;
        --t;
        ans[s+i]=1;
    }
    if(i>n)for(i=1;i<=n*2;++i)puts(ans[i]?"pop":"push");
    else puts("-1");
    return 0;
}
