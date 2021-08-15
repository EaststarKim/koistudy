#include <stdio.h>
typedef long long L;
struct P{
    L x,y,z;
    P(){}
    P(L x,L y,L z):x(x),y(y),z(z){}
    P genvec(P a){return P(a.x-x,a.y-y,a.z-z);}
    L dot(P a){return x*a.x+y*a.y+z*a.z;}
    L cross(P a){
        P t=P(y*a.z-z*a.y,z*a.x-x*a.z,x*a.y-y*a.x);
        return t.dot(t);
    }
}s,a,b;
int main(){
    int i,n,cnt=0;
    L t,r;
    scanf("%lld%lld%lld%lld%lld%lld%lld",&s.x,&s.y,&s.z,&a.x,&a.y,&a.z,&n);
    a=s.genvec(a);
    for(i=1;i<=n;++i){
        scanf("%lld%lld%lld%lld",&b.x,&b.y,&b.z,&r);
        b=s.genvec(b),t=b.cross(a);
        if(b.dot(a)>0&&b.dot(a)<a.dot(a)&&t<r*r*a.dot(a))++cnt;
    }
    printf("%d",cnt);
    return 0;
}
