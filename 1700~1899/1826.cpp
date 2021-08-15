#include <bits/stdc++.h>
using namespace std;
struct al{
    int e,nx;
}a[400010];
int st[200010],t;
void make_al(int s,int e){a[++t]={e,st[s]},st[s]=t;}
int p[200010],stck[200010][2],lev[200010],l[200010],r[200010],tree[1<<19][2];
void dfs(int n,int p){
    int tp;
    stck[tp=1][0]=n;
    while(tp){
        n=stck[tp][0],p=stck[tp][1];
        if(!lev[n])lev[n]=lev[p]+1,l[n]=++t;
        for(;st[n];st[n]=a[st[n]].nx)if(a[st[n]].e!=p){
            stck[++tp][0]=a[st[n]].e,stck[tp][1]=n;
            break;
        }
        if(st[n]){
            st[n]=a[st[n]].nx;
            continue;
        }
        r[n]=t;
        --tp;
    }
}
void update(int n,int s,int e,int si,int ei,int k,int v){
    if(e<si||ei<s)return;
    if(si<=s&&e<=ei){
        if(tree[n][0]<k)tree[n][0]=k,tree[n][1]=v;
        return;
    }
    int l=n*2,r=l+1,m=(s+e)/2;
    update(l,s,m,si,ei,k,v);
    update(r,m+1,e,si,ei,k,v);
}
int query(int n,int s,int e,int k,int p){
    if(tree[n][0]>tree[p][0])p=n;
    if(s==e)return p;
    int l=n*2,r=l+1,m=(s+e)/2;
    return k>m?query(r,m+1,e,k,p):query(l,s,m,k,p);
}
int main(){
    int i,n,q,d,b,c;
    scanf("%d%d",&n,&q);
    for(i=2;i<=n;++i){
        scanf("%d",p+i);
        make_al(i,p[i]);
        make_al(p[i],i);
    }
    t=0;
    dfs(1,0);
    t=0;
    for(;q--;){
        scanf("%d%d%d",&b,&c,&d);
        if(tree[query(1,1,n,l[b],0)][1]==tree[query(1,1,n,l[c],0)][1]){
            puts("YES");
            if(d&&p[b])update(1,1,n,l[b],r[b],lev[b],++t),p[b]=0;
        }
        else{
            puts("NO");
            if(d&&p[c])update(1,1,n,l[c],r[c],lev[c],++t),p[c]=0;
        }
    }
    return 0;
}
