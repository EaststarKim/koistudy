#include <stdio.h>
#include <algorithm>
using namespace std;
struct al{
    int e,nx;
}a[200010];
int st[200010],idx[200010],s[200010],x[100010],y[100010],ans[200010],cnt;
void make_al(int s,int e){a[++cnt].nx=st[s],a[cnt].e=e,st[s]=cnt;}
void post_order(int p){
    int i;
    s[p]=cnt+1;
    for(i=st[p];i;i=a[i].nx)post_order(a[i].e);
    idx[p]=++cnt;
}
int t[800010],c[800010];
void update(int *t,int n,int s,int e,int si,int ei,int k){
    if(e<si||ei<s)return;
    if(si<=s&&e<=ei){
        t[n]+=k;
        return;
    }
    int m=(s+e)/2,l=n*2,r=l+1;
    update(t,l,s,m,si,ei,k);
    update(t,r,m+1,e,si,ei,k);
}
int chk(int n,int s,int e,int p){
    if(e<p||p<s)return 0;
    if(c[n])return 1;
    if(s==e)return 0;
    int m=(s+e)/2,l=n*2,r=l+1;
    return chk(l,s,m,p)|chk(r,m+1,e,p);
}
void propagation(int n,int s,int e){
    if(s==e){
        ans[s]=t[n];
        return;
    }
    int m=(s+e)/2,l=n*2,r=l+1;
    t[l]+=t[n],t[r]+=t[n];
    propagation(l,s,m);
    propagation(r,m+1,e);
}
int main(){
    int i,n,q,p,root;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;++i){
        scanf("%d",&p);
        if(p)make_al(p,i);
        else root=i;
    }
    cnt=0;
    post_order(root);
    for(i=1;i<=q;++i){
        scanf("%d%d",&p,x+i);
        if(p==1)scanf("%d",y+i);
    }
    for(;--i;){
        if(y[i]){
            if(chk(1,1,n,idx[x[i]]))continue;
            update(t,1,1,n,s[x[i]],idx[x[i]],y[i]);
        }
        else update(c,1,1,n,s[x[i]],idx[x[i]],1);
    }
    propagation(1,1,n);
    for(i=1;i<=n;++i)printf("%d\n",ans[idx[i]]);
    return 0;
}
