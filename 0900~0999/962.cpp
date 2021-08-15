#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int s,e,w;
    bool operator<(const data&r)const{
        return w<r.w;
    }
}a[1048577];
int g[1025],rnk[1025],ans;
int seek(int n){return n==g[n]?n:g[n]=seek(g[n]);}
void uf(int x,int y,int w){
    x=seek(x),y=seek(y);
    if(x==y)return;
    ans+=w;
    if(rnk[x]>rnk[y])g[x]=y;
    else{
        if(rnk[x]==rnk[y])++rnk[y];
        g[y]=x;
    }
}
int main(){
    int i,j,n,m=1,k,s,e;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j,++m)scanf("%d",&a[m].w),a[m].s=i,a[m].e=j;
    }
    for(i=1;i<=n;++i)g[i]=i;
    scanf("%d",&k);
    for(i=1;i<=k;++i){
        scanf("%d%d",&s,&e);
        uf(s,e,0);
    }
    sort(a+1,a+m);
    for(i=1;i<m;++i){
        uf(a[i].s,a[i].e,a[i].w);
    }
    printf("%d",ans);
    return 0;
}
