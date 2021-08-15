#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
struct data{
    int s,e,i;
    long long ans;
    bool operator<(const data&r)const{
        return i<r.i;
    }
}b[50010];
int a[30010],bit[30010][2],n,q,m;
long long ans;
bool cmp(data a,data b){return a.s/m==b.s/m?a.e<b.e:a.s<b.s;}
void update(int k,int v){
    int t=n,sum=0,cnt=v>0?1:0;
    while(t)sum+=bit[t][0],t-=t&-t;
    t=k;
    while(t)sum-=bit[t][0],cnt+=bit[t][1],t-=t&-t;
    ans+=(sum+cnt*k)*v;
    t=k;
    while(t<=n)bit[t][0]+=k*v,bit[t][1]+=v,t+=t&-t;
}
int main(){
    int i,t,s,e;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    scanf("%d",&q);
    for(i=1;i<=q;++i)scanf("%d%d",&b[i].s,&b[i].e),b[i].i=i;
    m=sqrt(n);
    sort(b+1,b+q+1,cmp);
    s=1,e=0;
    for(i=1;i<=q;++i){
        while(s<b[i].s)update(a[s],-1),++s;
        while(b[i].s<s)--s,update(a[s],1);
        while(e<b[i].e)++e,update(a[e],1);
        while(b[i].e<e)update(a[e],-1),--e;
        b[i].ans=ans;
    }
    sort(b+1,b+q+1);
    for(i=1;i<=q;++i)printf("%lld\n",b[i].ans);
    return 0;
}
