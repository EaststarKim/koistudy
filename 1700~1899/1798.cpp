#include <bits/stdc++.h>
using namespace std;
struct P{
    long long x,y;
    long long mag(){return x*x+y*y;}
}a[100010],p;
P genvec(P a,P b){return {b.x-a.x,b.y-a.y};}
bool cmpy(P a,P b){return a.y==b.y?a.x<b.x:a.y<b.y;}
int s(long long t){return t>0?1:(!t?0:-1);}
long long cp(P a,P b){return s(a.x*b.y-a.y*b.x);}
bool cmp(P a,P b){
    a=genvec(p,a),b=genvec(p,b);
    if(!cp(a,b))return a.mag()<b.mag();
    return cp(a,b)>0;
}
bool ccw(P s,P m,P e){
    P a=genvec(s,m),b=genvec(m,e);
    return cp(a,b)>0;
}
struct L{
    P d;
    int c,i;
    long long f(P a){return d.y*a.x-d.x*a.y+c;}
    bool operator<(const L&r)const{return cmp(d,r.d);}
}l[100010];
int st[100010],ans[100010],n;
void graham_scan(){
    int i,t=1;
    st[1]=1;
    for(i=2;i<n;++i){
        while(t&&!ccw(a[st[t-1]],a[st[t]],a[i]))--t;
        st[++t]=i;
    }
    n=t+1;
    for(i=0;i<n;++i)a[i]=a[st[i]];
}
int main(){
    int i,j,k,q,h,w,x,y,z;
    scanf("%d%d%d%d",&n,&q,&h,&w);
    for(i=0;i<n;++i)scanf("%lld%lld",&a[i].x,&a[i].y);
    swap(a[0],a[min_element(a,a+n,cmpy)-a]);
    p=a[0];
    sort(a+1,a+n,cmp);
    graham_scan();
    for(i=1;i<=q;++i){
        scanf("%d%d%d",&x,&y,&z);
        if(x<0||(!x&&y>0))x=-x,y=-y,z=-z;
        l[i]={{-y,x},z,i};
    }
    p={0,0};
    sort(l+1,l+q+1);
    for(j=0;;++j){
        x=cp(genvec(a[(j+n-1)%n],a[j]),l[1].d),y=cp(l[1].d,genvec(a[j],a[(j+1)%n]));
        if(!x||x*y>0)break;
    }
    for(k=j+1;;k=(k+1)%n){
        x=cp(genvec(a[(k+n-1)%n],a[k]),l[1].d),y=cp(l[1].d,genvec(a[k],a[(k+1)%n]));
        if(!x||x*y>0)break;
    }
    for(i=1;i<=q;++i){
        for(;;j=(j+1)%n){
            x=cp(genvec(a[(j+n-1)%n],a[j]),l[i].d),y=cp(l[i].d,genvec(a[j],a[(j+1)%n]));
            if(!x||x*y>0)break;
        }
        for(;;k=(k+1)%n){
            x=cp(genvec(a[(k+n-1)%n],a[k]),l[i].d),y=cp(l[i].d,genvec(a[k],a[(k+1)%n]));
            if(!x||x*y>0)break;
        }
        if(s(l[i].f(a[j]))*l[i].f(a[k])<0)ans[l[i].i]=1;
    }
    for(i=1;i<=q;++i)puts(ans[i]?"Yes":"No");
    return 0;
}
