#include <bits/stdc++.h>
using namespace std;
struct al{
    int e,d,nx;
}a[8010];
struct data{
    int i;
    long long c;
    bool operator<(const data&r)const{
        return c>r.c;
    }
};
int c[2510],st[2510],chk[2510],t;
long long d[2510],e[2510];
priority_queue<data> q;
void make_al(int s,int e,int d){a[++t]={e,d,st[s]},st[s]=t;}
int main(){
    int i,j,n,m,x,y,z;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%d",c+i);
    for(;m--;){
        scanf("%d%d%d",&x,&y,&z);
        make_al(x,y,z);
        make_al(y,x,z);
    }
    for(i=0;i<=n;++i)d[i]=1e18;
    d[1]=0;
    for(i=1;i<=n;++i){
        for(x=0,j=1;j<=n;++j)if(!chk[j]&&d[x]>d[j])x=j;
        if(x==n)break;
        for(j=1;j<=n;++j)e[j]=1e18;
        priority_queue<data>().swap(q);
        q.push({x,e[x]=d[x]});
        while(!q.empty()){
            data t=q.top();q.pop();
            if(e[t.i]!=t.c)continue;
            for(j=st[t.i];j;j=a[j].nx)if(e[a[j].e]>t.c+a[j].d*c[x])q.push({a[j].e,e[a[j].e]=t.c+a[j].d*c[x]});
        }
        for(j=1;j<=n;++j)d[j]=min(d[j],e[j]);
        chk[x]=1;
    }
    printf("%lld",d[n]);
    return 0;
}
