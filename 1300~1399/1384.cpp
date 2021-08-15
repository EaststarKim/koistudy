#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int i,s,e,w;
    bool operator<(const data&r)const{
        return w<r.w;
    }
}a[20010];
struct adjacency_list{
    int nx,ch,w,i;
}b[40010];
int g[5010],chk[20010],st[5010],n,m,cnt,lca;
int q[5010],l[5010],p[5010],t[5010],w[5010],spt[5010][15];
long long ans[20010],sum;
int seek(int n){return g[n]=(g[n]==n?n:g[n]=seek(g[n]));}
void make_al(int s,int e,int w,int i){b[++cnt].nx=st[s],b[cnt].ch=e,b[cnt].w=w,b[cnt].i=i,st[s]=cnt;}
void make_mst(){
    int i,s,e;
    for(i=1;i<=n;++i)g[i]=i;
    for(i=1;i<=m;++i){
        ans[i]=-1;
        s=seek(a[i].s),e=seek(a[i].e);
        if(s==e)continue;
        chk[i]=1,sum+=a[i].w,g[s]=e;
        make_al(a[i].s,a[i].e,a[i].w,a[i].i),make_al(a[i].e,a[i].s,a[i].w,a[i].i);
    }
}
void make_tree(){
    int i,j,f=0,r=1,pa,c;
    q[1]=1;
    while(f<r){
        pa=q[++f];
        for(i=st[pa];i;i=b[i].nx){
            c=b[i].ch;
            if(p[pa]==c)continue;
            q[++r]=c,p[c]=spt[c][0]=pa,l[c]=l[pa]+1,w[c]=b[i].w,t[c]=b[i].i;
        }
    }
    for(i=1;i<15;++i){
        for(j=1;j<=n;++j)spt[j][i]=spt[spt[j][i-1]][i-1];
    }
}
int LCA(int s,int e){
    int i;
    if(l[s]<l[e])swap(s,e);
    for(i=14;i>=0;--i)if(l[s]-l[e]>=1<<i)s=spt[s][i];
    if(s==e)return s;
    for(i=14;i>=0;--i)if(spt[s][i]!=spt[e][i])s=spt[s][i],e=spt[e][i];
    return p[s];
}
void f(int s,int W){
    s=seek(s);
    while(l[s]>l[lca])ans[t[s]]=sum-w[s]+W,s=g[s]=seek(p[s]);
}
int main(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)scanf("%d%d%d",&a[i].s,&a[i].e,&a[i].w),a[i].i=i;
    sort(a+1,a+m+1);
    make_mst();
    make_tree();
    for(i=1;i<=n;++i)g[i]=i;
    for(i=1;i<=m;++i)if(!chk[i]){
        ans[a[i].i]=sum;
        lca=LCA(a[i].s,a[i].e);
        f(a[i].s,a[i].w);
        f(a[i].e,a[i].w);
    }
    for(i=1;i<=m;++i)printf("%lld\n",ans[i]);
    return 0;
}
