#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
struct al{
    int e,nx;
}a[200010];
int st[100010],t,n;
void make_al(int s,int e){a[++t]={e,st[s]},st[s]=t;}
struct data{
    int idx,a[4];
    void init(){
        for(int i=0;i<3;++i)a[i]=1e9;
    }
    bool operator<(const data&r)const{
    	int i;
        for(i=0;i<3;++i)if(a[i]!=r.a[i])break;
        return a[i]<r.a[i];
    }
}d[100010];
struct que{
    int i,d;
    bool operator<(const que&r)const{
        return d>r.d;
    }
};
priority_queue<que> q;
void dijkstra(int x){
    int i;
    while(!q.empty()){
        que t=q.top();
        q.pop();
        if(d[t.i].a[x]!=t.d)continue;
        for(i=st[t.i];i;i=a[i].nx)if(d[a[i].e].a[x]>t.d+1)q.push({a[i].e,d[a[i].e].a[x]=t.d+1});
    }
}
int bit[100010];
int getmax(int k){
    int m=1e9;
    while(k)m=min(m,bit[k]),k-=k&-k;
    return m;
}
void update(int k,int v){while(k<=n)bit[k]=min(bit[k],v),k+=k&-k;}
int D[100010],ans[100010];
void getans(){
    int i;
    while(!q.empty()){
        que t=q.top();
        q.pop();
        if(D[t.i]!=t.d)break;
        for(i=st[t.i];i;i=a[i].nx)if(D[a[i].e]>t.d+1)ans[a[i].e]=ans[t.i],q.push({a[i].e,D[a[i].e]=t.d+1});
    }
}
int main(){
    int i,m,s,e;
    scanf("%d",&n);
    for(i=1;i<n;++i){
        scanf("%d%d",&s,&e);
        make_al(s,e);
        make_al(e,s);
    }
    for(i=1;i<=n;++i)d[i].init();
    for(i=0;i<3;++i){
        scanf("%d",&s);
        q.push({s,d[s].a[i]=0});
        dijkstra(i);
    }
    for(i=1;i<=n;++i)d[i].idx=i,bit[i]=1e9;
    sort(d+1,d+n+1);
    for(i=1;i<=n;++i)D[i]=1e9;
    int cnt=0;
    for(i=1;i<=n;++i){
        if(getmax(d[i].a[1]+1)>d[i].a[2])++cnt,ans[d[i].idx]=d[i].idx,q.push({d[i].idx,D[d[i].idx]=0});
        update(d[i].a[1]+1,d[i].a[2]);
    }
    getans();
    printf("%d\n",cnt);
    scanf("%d",&m);
    for(;m--;){
        scanf("%d",&s);
        printf("%d\n",ans[s]);
    }
    return 0;
}
