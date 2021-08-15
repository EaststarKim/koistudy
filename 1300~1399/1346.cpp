#include <stdio.h>
#include <algorithm>
using namespace std;
int x[10010],y[10010],z[10010],xn,yn,zn;
long long ans;
int main(){
    int i,j,m,n,s,t;
    scanf("%d%d",&m,&n);
    x[++xn]=y[++yn]=0,z[++zn]=m;
    for(i=1;i<=n;++i){
        scanf("%d%d",&s,&t);
        if(s==0)y[++yn]=t;
        if(s==60)x[++xn]=t;
        if(s==120)z[++zn]=t;
    }
    sort(z,z+zn+1);
    for(i=1;i<=xn;++i){
        for(j=1;j<=yn;++j)if(x[i]+y[j]<=m){
            ans+=zn-(lower_bound(z,z+zn,max(x[i],y[j]))-z)+1;
            t=lower_bound(z,z+zn,x[i]+y[j])-z;
            if(z[t]==x[i]+y[j])--ans;
        }
    }
    printf("%lld",ans);
    return 0;
}
