#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int e,t,nx;
}a[5010];
int st[2510],cnt;
void make_al(int s,int e,int t){a[++cnt]={e,t,st[s]},st[s]=cnt;}
int lev[2510],p[2510],t[2510],mn=1e9,mx;
void dfs(int n){
    int i;
    for(i=st[n];i;i=a[i].nx)if(!lev[a[i].e]){
        lev[a[i].e]=lev[n]+1;
        p[a[i].e]=n;
        t[a[i].e]=a[i].t;
        dfs(a[i].e);
    }
}
void f(int s,int e){
    if(lev[s]<lev[e])swap(s,e);
    for(;lev[s]>lev[e];)mn=min(mn,t[s]),mx=max(mx,t[s]),s=p[s];
    for(;s!=e;)mn=min(mn,min(t[s],t[e])),mx=max(mx,max(t[s],t[e])),s=p[s],e=p[e];
    return;
}
int main(){
    int i,n,s,e,t;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d%d%d",&s,&e,&t);
        make_al(s,e,t);
        make_al(e,s,t);
    }
    lev[1]=1;
    dfs(1);
    scanf("%d%d",&s,&e);
    f(s,e);
    printf("%d %d",mn,mx);
    return 0;
}
