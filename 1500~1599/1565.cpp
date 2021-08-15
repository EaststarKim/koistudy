#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct data{
    int x,y,w,yi;
}a[3010];
struct tree{
    long long s,lmx,rmx,mx;
}it[1<<14];
int cnt,b=1;
long long ans;
bool cmpx(data p,data q){return p.x<q.x;}
bool cmpy(data p,data q){return p.y<q.y;}
void update(int t){
    if(t==1)return;
    t/=2;
    int l=t*2,r=l+1;
    it[t].s=it[l].s+it[r].s;
    it[t].lmx=max(it[l].lmx,it[l].s+it[r].lmx);
    it[t].rmx=max(it[r].rmx,it[r].s+it[l].rmx);
    it[t].mx=max(max(it[l].mx,it[r].mx),max(it[t].s,it[l].rmx+it[r].lmx));
    update(t);
}
int main(){
    int i,j,n,st,x,t;
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
    sort(a,a+n,cmpy);
    for(i=1;i<n;++i){
        if(a[i].y!=a[i-1].y)++cnt;
        a[i].yi=cnt;
    }
    sort(a,a+n,cmpx);
    while(b<=cnt)b*=2;
    for(i=0;i<n;i=st){
        st=0;
        memset(it,0,sizeof it);
        for(j=i;j<n;){
            x=a[j].x;
            for(;j<n&&a[j].x==x;++j){
                t=b+a[j].yi;
                it[t].s+=a[j].w;
                it[t].lmx=it[t].rmx=it[t].mx=it[t].s;
                update(t);
            }
            if(!st)st=j;
            ans=max(ans,it[1].mx);
        }
    }
    printf("%lld",ans);
    return 0;
}
