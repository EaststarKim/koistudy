#include <stdio.h>
#include <algorithm>
using namespace std;
struct al{
    int e,nx;
}a[20010];
int s[10010],st[10010],chk[10010],mi[10010],m,ans,ai=1e5;
void make_al(int s,int e){a[++m].nx=st[s],a[m].e=e,st[s]=m;}
void dfs(int p){
    int i,m1=0,m2=0,mi1=1e5,mi2=1e5;
    chk[p]=1;
    for(i=st[p];i;i=a[i].nx)if(!chk[a[i].e]){
        dfs(a[i].e);
        if(m1<=s[a[i].e]){
            mi2=mi1;
            if(m1<s[a[i].e])mi1=mi[a[i].e];
            else mi1=min(mi1,mi[a[i].e]);
            m2=m1,m1=s[a[i].e];
        }
        else if(m2<=s[a[i].e]){
            if(m2<s[a[i].e])mi2=mi[a[i].e];
            else mi2=min(mi2,mi[a[i].e]);
            m2=s[a[i].e];
        }
    }
    mi[p]=mi1;
    if(!m1)mi[p]=min(p,mi1);
    s[p]+=m1;
    if(!m2)mi2=p;
    if(ans==m2+s[p])ai=min(ai,min(mi[p],mi2));
    if(ans<m2+s[p])ans=m2+s[p],ai=min(mi[p],mi2);
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
    printf("%d %d",ans,ai);
    return 0;
}
