#include <stdio.h>
#include <algorithm>
using namespace std;
struct P{
    long long x,y;
}a[100010],p;
int st[100010],n,t;
long long ans,d;
P genvec(P a,P b){return {b.x-a.x,b.y-a.y};}
bool ccw(P s,P m,P e){
    P a=genvec(s,m),b=genvec(m,e);
    return a.x*b.y<=b.x*a.y;
}
bool cmp(P a,P b){
    a=genvec(p,a),b=genvec(p,b);
    return a.x*b.y>b.x*a.y;
}
void graham_scan(){
    int i;
    t=2;
    st[0]=n,st[1]=1,st[2]=2;
    for(i=3;i<=n;++i){
        while(ccw(a[st[t-1]],a[st[t]],a[i]))--t;
        st[++t]=i;
    }
}
long long dis(P a,P b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
int main(){
    int i,j;
    scanf("%d",&n);
    p.y=1e8;
    for(i=1;i<=n;++i){
        scanf("%lld%lld",&a[i].x,&a[i].y);
        if(p.y>a[i].y)p=a[i];
    }
    sort(a+1,a+n+1,cmp);
    graham_scan();
    for(i=1,j=2;i<=t;){
        d=dis(a[st[i]],a[st[j]]);
        ans=max(ans,d);
        j=(j<t?j:0)+1;
        if(dis(a[st[i]],a[st[j]])<d)++i,j=(j>1?j-1:t);
    }
    printf("%lld",ans);
    return 0;
}
