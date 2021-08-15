#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct data{
    int x,s,e,t;
    data(){}
    data(int x,int s,int e,int t):x(x),s(s),e(e),t(t){}
    bool operator<(const data&r)const{
        return x<r.x;
    }
}a[2010];
struct segment{
    int chk;
    long long sum;
}tree[1<<13];
int yi[2010],cnt=1;
long long ans;
void update(int n,int s,int e,int si,int ei,int t){
    if(ei<s||e<si)return;
    int m=(s+e)/2,l=n*2,r=l+1;
    if(si<=s&&e<=ei)tree[n].chk+=t;
    else{
        update(l,s,m,si,ei,t);
        update(r,m+1,e,si,ei,t);
    }
    tree[n].sum=0;
    if(!tree[n].chk)tree[n].sum=tree[l].sum+tree[r].sum;
    else if(tree[n].chk&&s<=e)tree[n].sum=yi[e+1]-yi[s];
}
int main(){
    int i,n,x,y,z,w;
    scanf("%d",&n);
    n*=2;
    for(i=1;i<=n;i+=2){
        scanf("%d%d%d%d",&x,&y,&z,&w);
        yi[i]=w,yi[i+1]=y;
        a[i]=data(x,w,y,1),a[i+1]=data(z,w,y,-1);
    }
    sort(yi+1,yi+n+1);
    for(i=2;i<=n;++i)if(yi[cnt]!=yi[i])yi[++cnt]=yi[i];
    sort(a+1,a+n+1);
    for(i=1;i<=n;++i){
        ans+=tree[1].sum*(a[i].x-a[i-1].x);
        a[i].s=lower_bound(yi+1,yi+cnt+1,a[i].s)-yi;
        a[i].e=lower_bound(yi+1,yi+cnt+1,a[i].e)-yi;
        update(1,1,cnt,a[i].s,a[i].e-1,a[i].t);
    }
    printf("%lld",ans);
    return 0;
}
