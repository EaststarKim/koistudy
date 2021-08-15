#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
struct al{
    int e,t,nx;
}a[1000010];
int st[100010],cnt,n;
void make_al(int s,int e,int t){a[++cnt]={e,t,st[s]},st[s]=cnt;}
struct data{
    int idx,a[4];
    void init(){
        for(int i=0;i<3;++i)a[i]=2e9;
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
        for(i=st[t.i];i;i=a[i].nx)
            if(d[a[i].e].a[x]>t.d+a[i].t)q.push({a[i].e,d[a[i].e].a[x]=t.d+a[i].t});
    }
}
int tmp[100010];
int bit[100010];
int getmax(int k){
    int m=1e9;
    while(k)m=min(m,bit[k]),k-=k&-k;
    return m;
}
void update(int k,int v){while(k<=n)bit[k]=min(bit[k],v),k+=k&-k;}
int ans[100010];
int main(){
    int i,j,m,s,e,t;
    int x[3];
    scanf("%d",&n);
    for(i=0;i<3;++i)scanf("%d",x+i);
    scanf("%d",&m);
    for(i=1;i<=m;++i){
        scanf("%d%d%d",&s,&e,&t);
        make_al(s,e,t);
        make_al(e,s,t);
    }
    for(i=1;i<=n;++i)d[i].init();
    for(i=0;i<3;++i){
        q.push({x[i],d[x[i]].a[i]=0});
        dijkstra(i);
    }
    for(i=1;i<=n;++i)tmp[i]=d[i].a[1];
    sort(tmp+1,tmp+n+1);
    for(i=1;i<=n;++i)d[i].a[1]=lower_bound(tmp+1,tmp+n+1,d[i].a[1])-tmp;
    for(i=1;i<=n;++i)d[i].idx=i,bit[i]=2e9;
    sort(d+1,d+n+1);
    for(i=j=1;i<=n;++i){
        if(d[i].a[0]>d[j].a[0])for(;j<i;++j)update(d[j].a[1],d[j].a[2]);
        if(getmax(d[i].a[1]-1)>=d[i].a[2])ans[d[i].idx]=1;
    }
    scanf("%d",&m);
    for(;m--;){
        scanf("%d",&s);
        puts(ans[s]?"YES":"NO");
    }
    return 0;
}
