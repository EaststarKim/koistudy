#include <stdio.h>
#include <algorithm>
using namespace std;
struct al{
    int e,nx;
}a[200010];
int st[200010],cnt;
void make_al(int s,int e){a[++cnt]={e,st[s]},st[s]=cnt;}
int k[100010],s[100010],e[100010];
int t[1<<19][2],chk[200010];
void init(int n,int s,int e){
    if(s==e){
        t[n][0]=1,t[n][1]=s;
        return;
    }
    int l=n*2,r=l+1,m=(s+e)/2;
    init(l,s,m);
    init(r,m+1,e);
    t[n][0]=t[l][0]+t[r][0];
}
int seek(int n,int s,int e,int k){
    if(s==e)return s;
    int l=n*2,r=l+1,m=(s+e)/2;
    if(t[l][0]<k)return seek(r,m+1,e,k-t[l][0]);
    return seek(l,s,m,k);
}
void update(int n,int s,int e,int si,int ei,int i){
    if(ei<s||e<si)return;
    if(si<=s&&e<=ei){
        t[n][0]=(e==ei);
        if(t[n][1]){
            if(chk[t[n][1]]<i)chk[t[n][1]]=i,make_al(i,t[n][1]);
            t[n][1]=i;
            return;
        }
        t[n][1]=i;
    }
    int l=n*2,r=l+1,m=(s+e)/2;
    update(r,m+1,e,si,ei,i);
    update(l,s,m,si,ei,i);
    t[n][0]=t[l][0]+t[r][0];
}
int d[200010][3],r;
int f(int x){return x==r?1:(x<r?0:2);}
void sol(int s){
    int i;
    if(!st[s]){
        d[s][0]=f(k[s-1]),d[s][1]=1,d[s][2]=f(k[s]);
        return;
    }
    for(i=st[s];i;i=a[i].nx)sol(a[i].e);
    for(i=st[s];i;i=a[i].nx){
        d[s][0]=max(d[s][0],d[a[i].e][0]);
        d[s][2]=max(d[s][2],d[a[i].e][2]);
    }
    int cnt[3]={};
    for(i=st[s];i;i=a[i].nx)++cnt[d[a[i].e][0]];
    d[s][1]=2;
    for(i=st[s];i;i=a[i].nx){
        --cnt[d[a[i].e][0]];
        ++cnt[d[a[i].e][1]];
        d[s][1]=min(d[s][1],cnt[2]+1);
        --cnt[d[a[i].e][1]];
        ++cnt[d[a[i].e][2]];
    }
}
int ans,p=1e9;
void findp(int s,int t){
    int i;
    if(!st[s]){
        ++t;
        if(ans==t)p=min(p,s);
        if(ans<t)ans=t,p=s;
        return;
    }
    int cnt[3]={};
    for(i=st[s];i;i=a[i].nx)++cnt[d[a[i].e][0]];
    for(i=st[s];i;i=a[i].nx){
        --cnt[d[a[i].e][0]];
        ++cnt[d[a[i].e][1]];
        findp(a[i].e,cnt[2]?0:t+1);
        --cnt[d[a[i].e][1]];
        ++cnt[d[a[i].e][2]];
    }
}
int main(){
    int i,n,c;
    scanf("%d%d%d",&n,&c,&r);
    for(i=1;i<n;++i)scanf("%d",k+i);
    init(1,1,n);
    for(i=1;i<=c;++i){
        scanf("%d%d",s+i,e+i);
        s[i]=(s[i]?seek(1,1,n,s[i]):0)+1,e[i]=seek(1,1,n,e[i]+1);
        update(1,1,n,s[i],e[i],n+i);
    }
    sol(n+c);
    findp(n+c,0);
    printf("%d",p-1);
    return 0;
}
