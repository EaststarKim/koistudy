#include <stdio.h>
#include <algorithm>
using namespace std;
struct al{
    int e,nx;
}a[40010];
int s[20010],st[20010],chk[20010],m,ans=-1e8;
void make_al(int s,int e){a[++m].nx=st[s],a[m].e=e,st[s]=m;}
void dfs(int p){
    int i,m1=0,m2=0;
    chk[p]=1;
    for(i=st[p];i;i=a[i].nx)if(!chk[a[i].e]){
        dfs(a[i].e);
        if(m1<=s[a[i].e])m2=m1,m1=s[a[i].e];
        else m2=max(m2,s[a[i].e]);
    }
    ans=max(ans,m1+m2+s[p]);
    s[p]+=m1;
}
int main(){
    int i,n,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",s+i);
    for(i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        make_al(x,y),make_al(y,x);
    }
    dfs(1);
    printf("%d",ans);
    return 0;
}
