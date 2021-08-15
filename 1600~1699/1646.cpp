#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
#define F first
#define S second
#define B begin()
#define E end()
vector<pii> x,y;
int a[20],chk[1<<20],n,ans;
void f(int i,int s,int t){
    if(i>=n){
        if(i%2)x.push_back({s,t});
        else y.push_back({s,t});
        return;
    }
    f(i+2,s,t);
    f(i+2,s+a[i],t+(1<<i));
    f(i+2,s-a[i],t+(1<<i));
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%d",a+i);
    f(0,0,0);
    f(1,0,0);
    sort(x.B,x.E);x.resize(unique(x.B,x.E)-x.B);
    sort(y.B,y.E);y.resize(unique(y.B,y.E)-y.B);
    for(auto i:x){
        for(auto j=lower_bound(y.B,y.E,pii(i.F,0));j!=y.E&&j->F==i.F;++j)chk[(i.S)|(j->S)]=1;
    }
    for(i=1;i<(1<<n);++i)ans+=chk[i];
    printf("%d",ans);
    return 0;
}
