#include <stdio.h>
int a[1010];
int main(){
    int i,j,n,t;
    scanf("%d%d",&n,&t);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=2;i<=n;++i){
        for(j=i;j>1;--j)if(a[j-1]<a[j])a[j]^=a[j-1]^=a[j]^=a[j-1];
    }
    if(t<2)for(i=1;i<=n;++i)printf("%d ",a[i]);
    else for(i=n;i>0;--i)printf("%d ",a[i]);
    return 0;
}
