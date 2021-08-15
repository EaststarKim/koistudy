#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int x,y;
    bool operator<(const data&r)const{
        return x<r.x;
    }
}t[1000010],a[6000010];
int st[6000010],vis[1000010],chk[6000010],flag[1000010],stck[1000010],s;
long long ans=1e18;
long long d(data a,data b){return (long long)(a.x-b.x)*(a.x-b.x)+(long long)(a.y-b.y)*(a.y-b.y);}
void dfs(){
    int i,p,t=0;
    stck[++t]=s;
    for(;t;){
        p=stck[t];
        ++flag[p];
        for(i=st[p];a[i].x==p;++i,st[p]=i)if(!flag[a[i].y]){
            if(p==s)vis[a[i].y]=1;
            if(a[i].y==s){
                if(vis[p])continue;
            }
            chk[i]=1;
            stck[++t]=a[i].y;
            break;
        }
        if(a[i].x!=p)--flag[stck[--t]];
    }
}
int main(){
    int i,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%d%d",&t[i].x,&t[i].y);
    for(i=1;i<=m;++i){
        scanf("%d%d",&a[i].x,&a[i].y);
        a[m+i]=a[i];
        swap(a[m+i].x,a[m+i].y);
    }
    m*=2;
    sort(a,a+m+1);
    for(i=1;i<=m;++i)if(a[i].x!=a[i-1].x)st[a[i].x]=i;
    scanf("%d",&s);
    flag[s]=-1;
    dfs();
    for(i=1;i<=n;++i)if(flag[i])ans=min(ans,d(t[s],t[i]));
    printf("%lld",ans);
    return 0;
}
