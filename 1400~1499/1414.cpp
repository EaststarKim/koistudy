#include <stdio.h>
#include <stdlib.h>
struct data{
    long long x;
    int d;
}a[100010];
long long ans[100010];
int main(){
    int i,j,n,q;
    long long t,k;
    scanf("%d%lld%d",&n,&t,&q);
    for(i=1;i<=n;++i)scanf("%lld%d",&a[i].x,&a[i].d);
    for(i=2,j=1;i<=n;++i){
        if(a[i].d==2){
            if(a[i-1].d==1)k=(a[i-1].x+a[i].x)/2;
        }
        else{
            if(a[i-1].d==2){
                if(a[j].d==1)for(;j<i;++j)ans[j]=(llabs(k-a[j].x)>t?a[j].x+(3-2*a[j].d)*t:k);
                else for(;j<i;++j)ans[j]=a[j].x-t;
            }
        }
    }
    if(a[n].d==1)for(;j<=n;++j)ans[j]=a[j].x+t;
    else for(;j<=n;++j)ans[j]=(llabs(k-a[j].x)>t?a[j].x+(3-2*a[j].d)*t:k);
    for(;q--;){
        scanf("%d",&i);
        printf("%lld\n",ans[i]);
    }
    return 0;
}
