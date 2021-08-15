#include <stdio.h>
#include <algorithm>
using namespace std;
int a[51][51],b[51],n,e;
double d[51][51],ans=1e5;
void f(int p,int v,double s){
    int i;
    if(s>=d[p][v])return;
    d[p][v]=s;
    if(p==e)return;
    for(i=1;i<=n;++i)if(a[p][i])f(i,max(v,b[i]),s+(double)a[p][i]/v);
}
int main(){
    int i,j,m,k,x,y,z;
    scanf("%d%d%d%d",&n,&m,&e,&k);
    for(;m--;){
        scanf("%d%d%d",&x,&y,&z);
        if(a[x][y])z=min(a[x][y],z);
        a[x][y]=a[y][x]=z;
    }
    for(i=1;i<=n;++i)b[i]=1;
    for(;k--;)scanf("%d%d",&x,&y),b[y]=x;
    for(i=1;i<=n;++i)for(j=1;j<51;++j)d[i][j]=1e5;
    f(1,b[1],0);
    for(i=1;i<51;++i)ans=min(ans,d[e][i]);
    printf("%.3lf",ans);
    return 0;
}
