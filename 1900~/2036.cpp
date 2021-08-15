#include <stdio.h>
int a[110],p[110];
int main(){
    int i,n,t;
    long long m;
    scanf("%d%lld",&n,&m);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(p[1]=i=t=1;m--;){
        if(p[a[i]]){
            m%=p[i]-p[a[i]]+1;
            i=a[i];
            break;
        }
        p[i=a[i]]=++t;
    }
    for(;m-->0;i=a[i]);
    printf("%d",i);
    return 0;
}
