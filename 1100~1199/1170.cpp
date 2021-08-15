#include <stdio.h>
int a[10],mx,mx2;
int main(){
    int i,k,n,m;
    scanf("%d%d",&k,&n);
    for(i=1;i<=n;++i)scanf("%d",&m),++a[m];
    for(i=1;i<=k;++i){
        if(mx<=a[i]){
            if(mx>mx2)mx2=mx;
            mx=a[i];
        }
        else if(mx2<a[i])mx2=a[i];
    }
    if(mx==mx2)puts("-1");
    else for(i=1;i<=k;++i)if(mx2==a[i])printf("%d ",i);
    return 0;
}
