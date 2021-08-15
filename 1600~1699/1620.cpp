#include <stdio.h>
#define M 1000000007
struct Node{
    int sum,cnt,n,l,r;
    Node(){}
    Node(int sum,int cnt,int n,int l,int r):sum(sum),cnt(cnt),n(n),l(l),r(r){}
    int update(int s,int e,int k,int v);
}root[6000010];
int idx[300010],t;
int Node::update(int s,int e,int k,int v){
    if(e<k||k<s)return n;
    if(s==e){
        root[++t]={v,1,t,0,0};
        return t;
    }
    int m=(s+e)/2,tmp=++t;
    root[tmp]=Node((sum+v)%M,cnt+1,tmp,root[l].update(s,m,k,v),root[r].update(m+1,e,k,v));
    return tmp;
}
int query(int a,int b,int s,int e,int si,int ei){
    if(e<si||ei<s)return 0;
    if(si<=s&&e<=ei)return ((root[b].sum)-(root[a].sum))%M;
    int m=(s+e)/2;
    return (query(root[a].l,root[b].l,s,m,si,ei)+query(root[a].r,root[b].r,m+1,e,si,ei))%M;
}
int getcnt(int a,int b,int s,int e,int si,int ei){
    if(e<si||ei<s)return 0;
    if(si<=s&&e<=ei)return ((root[b].cnt)-(root[a].cnt))%M;
    int m=(s+e)/2;
    return (getcnt(root[a].l,root[b].l,s,m,si,ei)+getcnt(root[a].r,root[b].r,m+1,e,si,ei))%M;
}
int a[300010];
long long f[300010]={1},sum;
int main(){
    int i,n,q,s,e;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;++i)f[i]=f[i-1]*i%M;
    for(i=1;i<=n;++i){
        scanf("%d",a+i);
        idx[i]=root[idx[i-1]].update(1,n,a[i],f[n-i]);
        sum=(sum+(a[i]-getcnt(0,idx[i],1,n,1,a[i]))*f[n-i])%M;
    }
    ++sum;
    for(;q--;){
        scanf("%d%d",&s,&e);
        long long ans=sum;
        ans=(ans-((a[s]-getcnt(0,idx[s],1,n,1,a[s]))*f[n-s])+((a[s]-getcnt(0,idx[e],1,n,1,a[s]))*f[n-e]))%M;
        ans=(ans-((a[e]-getcnt(0,idx[e],1,n,1,a[e]))*f[n-e])+((a[e]-getcnt(0,idx[s-1],1,n,1,a[e])-1)*f[n-s]))%M;
        if(a[s]<a[e])ans=(ans+query(idx[s],idx[e-1],1,n,a[s]+1,a[e]-1))%M;
        else ans=(ans-query(idx[s],idx[e-1],1,n,a[e]+1,a[s]-1))%M;
        printf("%d\n",(ans+M)%M);
    }
    return 0;
}
