#include <bits/stdc++.h>
using namespace std;
struct Point{
    long long x,y;
    bool operator<(const Point&r)const{return x<r.x||x==r.x&&y<r.y;}
    Point operator-(const Point&r)const{return {x-r.x,y-r.y};}
    long long operator*(const Point&r)const{return x*r.y-y*r.x;}
    long long sz(){return x*x+y*y;}
    void scan(){scanf("%lld%lld",&x,&y);}
}c[30010],v[30010],a[30010],b[30010];
int n,tp;
long long ans=1e18;
void graham_scan(){
    int i;
    swap(a[1],*min_element(a+1,a+n+1));
    for(i=n;i;--i)a[i]=a[i]-a[1];
    sort(a+2,a+n+1,[](Point p,Point q){return p*q>0||p*q==0&&p.sz()<q.sz();});
    b[0]=a[1],b[tp=1]=a[2];
    for(i=3;i<=n;++i){
        while(tp&&(b[tp]-b[tp-1])*(a[i]-b[tp])<=0)--tp;
        b[++tp]=a[i];
    }
    ++tp;
}
long long f(int t){
    int i,j;
    long long d=0;
    for(i=1;i<=n;++i)a[i]={c[i].x+v[i].x*t,c[i].y+v[i].y*t};
    graham_scan();
    for(t=i=0,j=max_element(b,b+tp)-b;t++<tp;){
        d=max(d,(b[j]-b[i]).sz());
        (b[(i+1)%tp]-b[i])*(b[(j+1)%tp]-b[j])>0?j=(j+1)%tp:++i;
    }
    ans=min(ans,d);
    return d;
}
int main(){
    int i,t;
    scanf("%d%d",&n,&t);
    for(i=1;i<=n;++i)c[i].scan(),v[i].scan();
    int l=0,r=t,p,q;
    while(l<=r){
        p=(l*2+r)/3,q=(l+r*2+1)/3;
        if(f(p)<=f(q))r=q-1;
        else l=p+1;
    }
    printf("%d\n%lld",l,ans);
    return 0;
}
