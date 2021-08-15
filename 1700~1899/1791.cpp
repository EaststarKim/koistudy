#include <bits/stdc++.h>
using namespace std;
struct al{
    int e,t,nx;
}a[5010];
int D[5010][5010],c[5010],st[5010],cnt;
void make_al(int s,int e,int t){a[++cnt]={e,t,st[s]},st[s]=cnt;}
int main(){
    int i,j,k,n,m,t,x,y,z;
    scanf("%d%d%d",&n,&m,&t);
    for(;m--;)scanf("%d%d%d",&x,&y,&z),make_al(x,y,z);
    for(i=1;i<=n;++i)scanf("%d",c+i);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)D[i][j]=t+1;
    }
    D[1][1]=0;
    for(i=1;i<n;++i){
        for(j=1;j<=n;++j)if(D[i][j]<t){
            for(k=st[j];k;k=a[k].nx)if(D[i][j]+a[k].t+c[a[k].e]<=t)D[i+1][a[k].e]=min(D[i+1][a[k].e],D[i][j]+a[k].t+c[a[k].e]);
        }
    }
    for(i=n;i;--i)if(D[i][n]<=t)break;
    if(i)printf("%d\n%d",i,D[i][n]);
    else puts("-1");
    return 0;
}
