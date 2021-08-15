#include <stdio.h>
#include <algorithm>
using namespace std;
struct adjacency_list{
    int nx,e,w;
}a[1000010];
int st[500010],cnt,n,k;
int b[500010],chk[500010],g[500010],vis[500010],c1[500010],c2[500010];
long long mnd[500010],mxd[500010],m1[500010],m2[500010],sum;
void make_al(int s,int e,int w){a[++cnt]={st[s],e,w},st[s]=cnt;}
void make_tree(int p){
    int i;
    long long s;
    vis[p]=1;
    for(i=st[p];i;i=a[i].nx)if(!vis[a[i].e]){
        make_tree(a[i].e);
        if(chk[a[i].e]<k){
            chk[p]+=chk[a[i].e];
            if(chk[a[i].e]){
                sum+=a[i].w;
                s=m1[a[i].e]+a[i].w;
                if(m1[p]<=s)c2[p]=c1[p],m2[p]=m1[p],c1[p]=a[i].e,m1[p]=s;
                else if(m2[p]<=s)c2[p]=a[i].e,m2[p]=s;
            }
        }
    }
}
void min_dis(int p){
    int i;
    for(i=st[p];i;i=a[i].nx){
        if(!mnd[a[i].e]&&!chk[a[i].e]){
            mnd[a[i].e]=mnd[p]+a[i].w;
            g[a[i].e]=g[p];
            min_dis(a[i].e);
        }
    }
}
void max_dis(int p,long long s){
    int i;
    vis[p]=2;
    mxd[p]=max(s,m1[p]);
    for(i=st[p];i;i=a[i].nx)if(chk[a[i].e]&&vis[a[i].e]<2){
        if(c1[p]!=a[i].e)max_dis(a[i].e,a[i].w+max(s,m1[p]));
        else max_dis(a[i].e,a[i].w+max(s,m2[p]));
    }
}
int main(){
    int i,x,y,z,lca;
    scanf("%d%d",&n,&k);
    for(i=1;i<n;++i){
        scanf("%d%d%d",&x,&y,&z);
        make_al(x,y,z);
        make_al(y,x,z);
    }
    for(i=1;i<=k;++i)scanf("%d",b+i),chk[b[i]]=1;
    make_tree(1);
    for(i=1;i<=n;++i)if(chk[i]==k)lca=i;
    max_dis(lca,0);
    for(i=1;i<=n;++i)if(chk[i])g[i]=i,min_dis(i);
    long long mn=1e18;
    for(i=1;i<=n;++i)mn=min(mn,mnd[i]+sum*2-mxd[g[i]]);
    printf("%lld",mn);
    return 0;
}
