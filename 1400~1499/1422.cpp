#include <stdio.h>
#include <map>
using namespace std;
map<int,int> a,b;
int x[5010],y[5010],xcnt[5010],ycnt[5010],s,t,ans;
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d%d",x+i,y+i);
        if(!a[x[i]])a[x[i]]=++s;
        ++xcnt[a[x[i]]];
        if(!b[y[i]])b[y[i]]=++t;
        ++ycnt[b[y[i]]];
    }
    for(i=1;i<=n;++i)ans+=(xcnt[a[x[i]]]-1)*(ycnt[b[y[i]]]-1);
    printf("%d",ans);
    return 0;
}
