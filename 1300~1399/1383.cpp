#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int s,e,w;
    bool operator<(const data&r)const{
        return w<r.w;
    }
}a[10010];
int g[510],n,m,cnt,ans;
int seek(int n){return g[n]=(g[n]==n?n:g[n]=seek(g[n]));}
void make_mst(){
    int i,s,e;
    for(i=1;i<=n;++i)g[i]=i;
    for(i=1;i<=m;++i){
        s=seek(a[i].s),e=seek(a[i].e);
        if(s==e)continue;
        ++cnt,ans+=a[i].w,g[s]=e;
        if(cnt==n-1){
            printf("%d",ans);
            return;
        }
    }
    puts("Impossible");
}
int main(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)scanf("%d%d%d",&a[i].s,&a[i].e,&a[i].w);
    sort(a+1,a+m+1);
    make_mst();
    return 0;
}
