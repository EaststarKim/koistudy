#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
struct al{
    int nx,e;
}a[400010];
struct data{
    int s;
    long long d;
    bool operator<(const data&r)const{
        return d>r.d;
    }
};
int st[100010],q[100010],chk[100010],t,f,r;
long long D[100010],d;
priority_queue<data> pq;
void make_al(int s,int e){a[++t].nx=st[s],a[t].e=e,st[s]=t;}
int main(){
    int i,n,m,k,l,x,y,s,e;
    scanf("%d%d%d%d%d%d",&n,&m,&k,&l,&x,&y);
    for(i=1;i<=k;++i){
        scanf("%d",&s);
        q[++r]=s,chk[s]=l+1;
    }
    for(i=1;i<=m;++i){
        scanf("%d%d",&s,&e);
        make_al(s,e),make_al(e,s);
    }
    while(f<r){
        s=q[++f];
        for(i=st[s];i;i=a[i].nx)if(!chk[a[i].e]){
            chk[a[i].e]=chk[s]-1;
            if(chk[s]>2)q[++r]=a[i].e;
        }
    }
    for(i=2;i<=n;++i)D[i]=1e11;
    pq.push({1,0});
    while(!pq.empty()){
        s=pq.top().s,d=pq.top().d;
        pq.pop();
        if(d!=D[s])continue;
        for(i=st[s];i;i=a[i].nx)if(chk[a[i].e]<=l){
            if(D[a[i].e]>d+(chk[a[i].e]?y:x))D[a[i].e]=d+(chk[a[i].e]?y:x),pq.push({a[i].e,D[a[i].e]});
        }
    }
    printf("%lld",D[n]-(chk[n]?y:x));
    return 0;
}
