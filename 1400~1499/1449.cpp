#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int s,e,nx;
}a[2000010];
int st[1000010],cnt,n;
void make_al(int s,int e){a[++cnt]={s,e,st[s]},st[s]=cnt;}
struct graph{
    int x,mxd,ccnt,csz;
    int d[1000010],g[1000010],rnk[1000010],sz[1000010];
    void init(int a){
        int i;
        x=a;
        for(i=1;i<=n;++i)g[i]=i,sz[i]=1;
    }
    int seek(int n){return g[n]==n?n:g[n]=seek(g[n]);}
    void uf(int a,int b){
        mxd=max(mxd,max(++d[a],++d[b]));
        a=seek(a),b=seek(b);
        if(a==b){
            ++ccnt;
            csz=sz[a];
            return;
        }
        if(rnk[a]>rnk[b])g[b]=a,sz[a]+=sz[b];
        else{
            if(rnk[a]==rnk[b])++rnk[b];
            g[a]=b,sz[b]+=sz[a];
        }
    }
}G[5];
void Link(int A,int B){
    int i,j,t;
    make_al(A,B);
    make_al(B,A);
    if(G[0].mxd<3){
        G[0].uf(A,B);
        if(G[0].d[B]>2)A=B;
        if(G[0].d[A]>2){
            t=0;
            G[++t].init(A);
            for(i=1;i<=cnt;i+=2)if(a[i].s!=A&&a[i].e!=A)G[t].uf(a[i].s,a[i].e);
            for(i=st[A];i;i=a[i].nx){
                G[++t].init(A=a[i].e);
                for(j=1;j<=cnt;j+=2)if(a[j].s!=A&&a[j].e!=A)G[t].uf(a[j].s,a[j].e);
            }
        }
    }
    else{
        for(i=1;i<5;++i)if(G[i].x!=A&&G[i].x!=B)G[i].uf(A,B);
    }
}
int CountCritical(){
    int i,ans=0;
    if(G[0].mxd<3){
        if(!G[0].ccnt)return n;
        if(G[0].ccnt<2)return G[0].csz;
        return 0;
    }
    for(i=1;i<5;++i)if(G[i].mxd<3&&!G[i].ccnt)++ans;
    return ans;
}
int main(){
    int l,a,b;
    scanf("%d%d",&n,&l);
    G[0].init(0);
    for(;l--;){
        scanf("%d",&a);
        if(a<0)printf("%d\n",CountCritical());
        else{
            scanf("%d",&b);
            Link(a+1,b+1);
        }
    }
    return 0;
}
