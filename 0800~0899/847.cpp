#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
struct data{
    int t,d;
    bool operator<(const data&r)const{
        if(t==r.t)return d<r.d;
        return t<r.t;
    }
}a[100010];
int tt[100010],td[100010],tn,dn;
long long Dt[100010],Dd[100010],t,d,ans;
int bsearch(int s,int e,int p,int t){
    if(s==e)return s;
    int m=(s+e)/2;
    if(t){
        if(p<=tt[m])return bsearch(s,m,p,t);
        else return bsearch(m+1,e,p,t);
    }
    else{
        if(p<=td[m])return bsearch(s,m,p,t);
        else return bsearch(m+1,e,p,t);
    }
}
int main()
{
    int i,n,l,x,y;
    scanf("%d%d",&n,&l);
    for(i=0;i<n;++i){
        scanf("%d%d",&a[i].t,&a[i].d);
        tt[tn++]=a[i].t;
        td[dn++]=a[i].d;
    }
    sort(a,a+n);
    sort(tt,tt+tn);
    sort(td,td+tn);
    for(i=0;i<n;++i){
        x=bsearch(0,tn,a[i].t,1);
        y=bsearch(0,dn,a[i].d,0);
        t=max(Dt[x],Dd[y]+abs(a[i].t-a[i].d)+l);
        d=max(Dd[y],Dt[x]+abs(a[i].t-a[i].d)+l);
        Dt[x]=t;
        Dd[y]=d;
    }
    for(i=0;i<tn;++i)ans=max(ans,Dt[i]);
    for(i=0;i<dn;++i)ans=max(ans,Dd[i]);
    printf("%lld",ans);
    return 0;
}
