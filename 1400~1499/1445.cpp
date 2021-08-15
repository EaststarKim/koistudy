#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
struct data{
    int e,t,nx;
}a[400010];
int st[200010],cnt;
void make_al(int s,int e,int t){a[++cnt]={e,t,st[s]},st[s]=cnt;}
int chk[200010],k;
int sum[200010];
void counting(int s,int p){
    int i;
    sum[s]=1;
    for(i=st[s];i;i=a[i].nx)if(!chk[a[i].e]&&a[i].e!=p){
        counting(a[i].e,s);
        sum[s]+=sum[a[i].e];
    }
}
int find_centroid(int s,int p,int n){
    int i;
    for(i=st[s];i;i=a[i].nx)if(!chk[a[i].e]&&a[i].e!=p){
        if(sum[a[i].e]>n/2)return find_centroid(a[i].e,s,n);
    }
    return s;
}
struct dis{
    int g,d,t;
    bool operator<(const dis&r)const{
        if(d==r.d)return t<r.t;
        return d<r.d;
    }
}b[200010];
bool cmp(dis a,dis b){return a.g<b.g;}
set<dis> S;
int ans=1e9,l;
void dfs(int s,int p,int g,int d,int t){
    int i;
    b[++l]={g,d,t};
    for(i=st[s];i;i=a[i].nx)if(!chk[a[i].e]&&a[i].e!=p)dfs(a[i].e,s,g,d+a[i].t,t+1);
}
void sol(int s){
    int i,j,g;
    chk[s]=1;
    for(i=st[s];i;i=a[i].nx)if(!chk[a[i].e]){
        counting(a[i].e,s);
        sol(find_centroid(a[i].e,s,sum[a[i].e]));
    }
    chk[s]=0;
    l=g=0;
    b[++l]={0,0,0};
    for(i=st[s];i;i=a[i].nx)if(!chk[a[i].e])dfs(a[i].e,s,++g,a[i].t,1);
    sort(b+1,b+l+1,cmp);
    S.clear();
    for(i=j=1;i<=l;++i){
        if(b[j].g<b[i].g)for(;j<i;++j)S.insert(b[j]);
        dis tmp={0,k-b[i].d,0};
        set<dis>::iterator it=S.lower_bound(tmp);
        if(it!=S.end()&&b[i].d+it->d==k)ans=min(ans,b[i].t+it->t);
    }
}
int main(){
    int i,n,s,e,t;
    scanf("%d%d",&n,&k);
    for(i=1;i<n;++i){
        scanf("%d%d%d",&s,&e,&t);
        ++s,++e;
        make_al(s,e,t);
        make_al(e,s,t);
    }
    counting(1,0);
    sol(find_centroid(1,0,n));
    if(ans==1e9)ans=-1;
    printf("%d",ans);
    return 0;
}
