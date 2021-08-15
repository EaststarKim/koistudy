#include <stdio.h>
int a[20][2],b,mx;
int main(){
    int i,j,n,m,k,s,t;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i)scanf("%d%d",a[i],a[i]+1);
    scanf("%d",&k);
    for(;k--;)scanf("%d",&s),b|=1<<(s-1);
    for(i=1;i<(1<<n);++i)if((i&b)==b){
        for(j=s=t=0;j<n;++j)if(i&(1<<j))t+=a[j][0],s+=a[j][1];
        if(t<=m&&mx<s)mx=s;
    }
    printf("%d",mx);
    return 0;
}
