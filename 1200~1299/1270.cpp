#include <stdio.h>
#include <algorithm>
using namespace std;
struct P{
    int x,y;
    P(){}
    P(int x,int y):x(x),y(y){}
    bool operator<(const P&r)const{
        return y<r.y;
    }
    P genvec(P e){return P(e.x-x,e.y-y);}
}a[100010];
bool cmp(P p,P q){
    p=a[0].genvec(p),q=a[0].genvec(q);
    return (long long)p.x*q.y>(long long)q.x*p.y;
}
bool ccw(P s,P m,P e){
    P a=s.genvec(m),b=m.genvec(e);
    return (long long)a.x*b.y-(long long)a.y*b.x<0;
}
int st[100010],chk[100010],n,t,ans;
void graham_scan(){
    int i;
    t=2;
    st[0]=n-1,st[1]=0,st[2]=1;
    for(i=2;i<n;++i){
        while(ccw(a[st[t-1]],a[st[t]],a[i]))--t;
        st[++t]=i;
    }
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%d%d",&a[i].x,&a[i].y);
    sort(a,a+n);
    sort(a+1,a+n,cmp);
    graham_scan();
    printf("%d",n*3-t*2-2);
    return 0;
}
