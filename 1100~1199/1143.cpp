#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 1000000007
using namespace std;
struct data{
    int a,i;
    bool operator<(const data&r)const{
        return a<r.a;
    }
}t[2010];
struct al{
    int nx,e;
}a[4010];
int st[2010],idx[2010],chk[2010],d,cnt;
long long ans;
void make_al(int s,int e){a[++cnt].nx=st[s],a[cnt].e=e,st[s]=cnt;}
long long f(int p,int k){
    int i;
    long long m=1;
    chk[p]=1;
    for(i=st[p];i;i=a[i].nx){
        if(!chk[a[i].e]&&a[i].e<k&&t[a[i].e].a+d>=t[k].a)m=(m*(f(a[i].e,k)+1))%M;
    }
    return m;
}
int main(){
    int i,n,s,e;
    scanf("%d%d",&d,&n);
    for(i=1;i<=n;++i)scanf("%d",&t[i].a),t[i].i=i;
    sort(t+1,t+n+1);
    for(i=1;i<=n;++i)idx[t[i].i]=i;
    for(i=1;i<n;++i){
        scanf("%d%d",&s,&e);
        s=idx[s],e=idx[e];
        make_al(s,e),make_al(e,s);
    }
    for(i=1;i<=n;++i){
        memset(chk,0,sizeof chk);
        ans=(ans+f(i,i))%M;
    }
    printf("%lld",ans);
    return 0;
}
