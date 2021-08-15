#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1010],b[1010],x[2010],chk[2010],D[2010];
int main(){
    int i,j,n,k;
    scanf("%d%d",&n,&k);
    for(i=1,n=0;i<=k;++i)scanf("%d%d",a+i,b+i),x[++n]=a[i],x[++n]=b[i];
    sort(x+1,x+n+1);
    for(i=1;i<=k;++i){
        a[i]=lower_bound(x+1,x+n+1,a[i])-x;
        b[i]=lower_bound(x+1,x+n+1,b[i])-x;
        if(a[i]>b[i])swap(a[i],b[i]);
        chk[b[i]]=max(chk[b[i]],a[i]);
    }
    for(i=1,j=0;i<=n;++i)D[i]=D[j=max(j,chk[i])]+1;
    printf("%d",D[n]);
    return 0;
}
