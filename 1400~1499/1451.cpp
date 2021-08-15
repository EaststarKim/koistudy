#include <stdio.h>
#include <map>
using namespace std;
#define MOD 1000000000
struct al{
    int e,nx;
}a[100010];
int st[100010],cnt,n;
void make_al(int s,int e){a[++cnt]={e,st[s]},st[s]=cnt;}
struct data{
    int x,y;
    bool operator<(const data&r)const{
        if(x==r.x)return y<r.y;
        return x<r.x;
    }
}v[100010];
map<data,int> M;
int d[100010][4];
int g[100010],sum[100010],chk[100010],m;
int x[]={-1,0,1,0},y[]={0,1,0,-1};
long long ans;
void dfs(int s,int p){
    int i;
    for(i=st[s];i;i=a[i].nx)if(a[i].e!=p){
        dfs(a[i].e,s);
        sum[s]+=sum[a[i].e];
    }
}
void sol(int s,int p){
    int i;
    for(i=st[s];i;i=a[i].nx)if(a[i].e!=p){
        ans=(ans+(long long)sum[a[i].e]*(n-sum[a[i].e]))%MOD;
        sol(a[i].e,s);
    }
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",&v[i].x,&v[i].y),M[v[i]]=i;
    for(i=1;i<=n;++i){
        for(j=0;j<4;++j){
            data tmp={v[i].x+x[j],v[i].y+y[j]};
            d[i][j]=M[tmp];
        }
    }
    for(i=1;i<=n;++i)if(!g[i]){
        chk[0]=++m;
        for(j=i;d[j][0];j=d[j][0]);
        for(;j;j=d[j][2]){
            ++sum[g[j]=m];
            if(chk[g[d[j][1]]]!=m)chk[g[d[j][1]]]=m,make_al(m,g[d[j][1]]),make_al(g[d[j][1]],m);
            if(chk[g[d[j][3]]]!=m)chk[g[d[j][3]]]=m,make_al(m,g[d[j][3]]),make_al(g[d[j][3]],m);
        }
    }
    dfs(1,0);
    sol(1,0);
    for(i=1;i<=n;++i)st[i]=g[i]=sum[i]=chk[i]=0;
    cnt=m=0;
    for(i=1;i<=n;++i)if(!g[i]){
        chk[0]=++m;
        for(j=i;d[j][1];j=d[j][1]);
        for(;j;j=d[j][3]){
            ++sum[g[j]=m];
            if(chk[g[d[j][0]]]!=m)chk[g[d[j][0]]]=m,make_al(m,g[d[j][0]]),make_al(g[d[j][0]],m);
            if(chk[g[d[j][2]]]!=m)chk[g[d[j][2]]]=m,make_al(m,g[d[j][2]]),make_al(g[d[j][2]],m);
        }
    }
    dfs(1,0);
    sol(1,0);
    printf("%lld",ans);
    return 0;
}
