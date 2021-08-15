#include <stdio.h>
int a[10],mx;
int main(){
    int i,k,n,m;
    scanf("%d%d",&k,&n);
    for(i=1;i<=n;++i)scanf("%d",&m),++a[m];
    for(i=1;i<=k;++i)if(mx<a[i])mx=a[i];
    for(i=1;i<=k;++i)if(mx==a[i])printf("%d ",i);
    return 0;
}
