#include <stdio.h>
#include <algorithm>
using namespace std;
struct adjacency_list{
    int e,t,nx;
}a[60010];
int st[30010],n,cnt;
int q[30010],l[30010],spt[30010][17],d[30010][17];
void make_al(int s,int e,int t){a[++cnt]={e,t,st[s]},st[s]=cnt;}
void make_tree(){
    int i,j,f=0,r=1,p,c;
    q[1]=l[1]=1;
    while(f<r){
        p=q[++f];
        for(i=st[p];i;i=a[i].nx){
            c=a[i].e;
            if(l[c])continue;
            q[++r]=c,spt[c][0]=p,d[c][0]=a[i].t,l[c]=l[p]+1;
        }
    }
    for(i=1;i<17;++i){
        for(j=1;j<=n;++j){
            spt[j][i]=spt[spt[j][i-1]][i-1];
            d[j][i]=d[j][i-1]+d[spt[j][i-1]][i-1];
        }
    }
}
long long f(int s,int e){
    int i;
    long long ans=0;
    if(spt[s][16]!=spt[e][16])return 0;
    if(l[s]<l[e])swap(s,e);
    for(i=16;i>=0;--i)if(l[s]-l[e]>=1<<i)ans+=d[s][i],s=spt[s][i];
    if(s==e)return ans;
    for(i=16;i>=0;--i)if(spt[s][i]!=spt[e][i])ans+=d[s][i]+d[e][i],s=spt[s][i],e=spt[e][i];
    return ans+d[s][0]+d[e][0];
}
int main(){
    int i,x,y,lca,s,e,t;
    scanf("%d",&n);
    for(i=1;i<n;++i){
        scanf("%d%d%d",&s,&e,&t);
        make_al(s,e,t);
        make_al(e,s,t);
    }
    make_tree();
    scanf("%d%d",&x,&y);
    printf("%lld",f(x,y));
    return 0;
}
