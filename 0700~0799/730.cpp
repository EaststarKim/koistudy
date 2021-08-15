#include <stdio.h>
#include <algorithm>
using namespace std;
struct al{
    int nx,e;
}a[50010];
int t[10010],D[10010],st[10010],in[10010],cnt,mx;
void make_al(int s,int e){a[++cnt].nx=st[s],a[cnt].e=e,st[s]=cnt;}
int main(){
    int i,j,n,m,s,e;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%d",t+i),D[i]=t[i];
    for(i=1;i<=m;++i)scanf("%d%d",&s,&e),make_al(s,e),++in[e];
    for(m=n;m;){
        for(i=1;i<=n;++i)if(!in[i]){
            for(j=st[i];j;j=a[j].nx)e=a[j].e,D[e]=max(D[e],D[i]+t[e]),--in[e];
            in[i]=-1;
            --m;
        }
    }
    for(i=1;i<=n;++i)mx=max(mx,D[i]);
    printf("%d",mx);
    return 0;
}
