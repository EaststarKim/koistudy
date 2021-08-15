#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int e,t,nx;
}a[100010];
int st[50010],cnt,n;
void make_al(int s,int e,int t){a[++cnt]={e,t,st[s]},st[s]=cnt;}
int chk[50010],K;
int sum[50010];
void counting(int s,int p){
    int i;
    sum[s]=1;
    for(i=st[s];i;i=a[i].nx)if(!chk[a[i].e]&&a[i].e!=p){
        counting(a[i].e,s);
        sum[s]+=sum[a[i].e];
    }
}
int find_centroid(int s,int p,int n){
    int i;
    for(i=st[s];i;i=a[i].nx)if(!chk[a[i].e]&&a[i].e!=p){
        if(sum[a[i].e]>n/2)return find_centroid(a[i].e,s,n);
    }
    return s;
}
struct dis{
    int g,d;
    bool operator<(const dis&r)const{
        return d<r.d;
    }
}b[50010],c[50010];
bool cmp(dis a,dis b){return a.g<b.g;}
int getsum(int k,int *bit){
    int s=0;
    while(k)s+=bit[k],k-=k&-k;
    return s;
}
void update(int k,int *bit){while(k<=n)++bit[k],k+=k&-k;}
int ans,l;
void dfs(int s,int p,int g,int d){
    int i;
    b[++l]={g,d};
    for(i=st[s];i;i=a[i].nx)if(!chk[a[i].e]&&a[i].e!=p)dfs(a[i].e,s,g,d+a[i].t);
}
void sol(int s){
    int i,j,k,g;
    chk[s]=1;
    for(i=st[s];i;i=a[i].nx)if(!chk[a[i].e]){
        counting(a[i].e,s);
        sol(find_centroid(a[i].e,s,sum[a[i].e]));
    }
    chk[s]=0;
    l=g=0;
    b[++l]={0,0};
    for(i=st[s];i;i=a[i].nx)if(!chk[a[i].e])dfs(a[i].e,s,++g,a[i].t);
    sort(b+1,b+l+1,cmp);
    for(i=1;i<=l;++i)c[i]=b[i];
    sort(c+1,c+l+1);
    int bit[50010]={};
    for(i=j=1;i<=l;++i){
        if(b[j].g<b[i].g){
            for(;j<i;++j){
                k=lower_bound(c+1,c+l+1,b[j])-c;
                update(k,bit);
            }
        }
        dis tmp={0,K-b[i].d};
        k=upper_bound(c+1,c+l+1,tmp)-c;
        ans+=getsum(k-1,bit);
    }
}
int main(){
    int i,s,e,t;
    scanf("%d%d",&n,&K);
    for(i=1;i<n;++i){
        scanf("%d%d%d",&s,&e,&t);
        make_al(s,e,t);
        make_al(e,s,t);
    }
    counting(1,0);
    sol(find_centroid(1,0,n));
    printf("%d",ans);
    return 0;
}
