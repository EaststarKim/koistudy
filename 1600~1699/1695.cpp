#include <stdio.h>
const int M=1e9+7;
struct al{
    int e,nx;
}a[600010];
int st[300010],t;
void make_al(int s,int e){a[++t]={e,st[s]},st[s]=t;}
int idx[300010],d[300010],q[300010],f,r,m,sz;
long long ans=1;
void dfs(int p,int t){
    int i;
    d[p]=t-1;
    ++sz;
    for(i=st[p];i;i=a[i].nx){
        if(d[a[i].e]==t){
            dfs(a[i].e,t);
            if(!sz)return;
        }
        else if(d[a[i].e]>t){
            sz=0;
            return;
        }
    }
}
int main(){
    int i,n,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d%d",&x,&y);
        if(!idx[x])idx[x]=++m;
        if(!idx[y])idx[y]=++m;
        make_al(x=idx[x],y=idx[y]);
        make_al(y,x);
        ++d[x],++d[y];
    }
    for(i=1;i<=m;++i)if(d[i]<2)q[++r]=i;
    for(;f<r;){
        x=q[++f];
        if(!d[x])continue;
        for(i=st[x];i;i=a[i].nx)if(d[a[i].e])if(--d[a[i].e]==1)q[++r]=a[i].e;
        d[x]=0;
    }
    for(i=1;i<=m;++i)if(d[i]>2)break;
    if(i<=m){
        puts("0");
        return 0;
    }
    for(i=1;i<=m;++i)if(!(d[i]&1))sz=-1,dfs(i,d[i]),ans=ans*(d[i]>0?2-!sz:sz+1)%M;
    printf("%d",ans);
    return 0;
}
