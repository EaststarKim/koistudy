#include <stdio.h>
#include <algorithm>
using namespace std;
int a[300010],b[300010],d[300010],e[300010],ans=-1e9;
int main(){
    int i,n,m;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i),b[i]=a[i];
    for(i=1;i<=n;++i)a[i]+=a[i-1];
    for(i=n;i;--i)b[i]+=b[i+1];
    d[1]=a[1],m=min(0,a[1]);
    for(i=2;i<=n;++i){
        d[i]=max(d[i-1],a[i]-m);
        m=min(m,a[i]);
    }
    e[n]=b[n],m=min(0,b[n]);
    for(i=n-1;i;--i){
        e[i]=max(e[i+1],b[i]-m);
        m=min(m,b[i]);
    }
    for(i=0;i<=n;++i)ans=max(ans,d[i]+e[i+1]);
    printf("%d",ans);
    return 0;
}
