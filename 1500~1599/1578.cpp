#include <stdio.h>
#include <algorithm>
using namespace std;
struct adjacency_list{
    int nx,e,w;
}a[1000010];
int st[500010],cnt,n,k;
int b[500010],chk[500010],vis[500010],ans;
long long sum;
void make_al(int s,int e,int w){a[++cnt]={st[s],e,w},st[s]=cnt;}
void make_tree(int p){
    int i;
    vis[p]=1;
    for(i=st[p];i;i=a[i].nx)if(!vis[a[i].e]){
        make_tree(a[i].e);
        if(chk[a[i].e]&&chk[a[i].e]<k){
            chk[p]+=chk[a[i].e];
            sum+=a[i].w;
            ++ans;
        }
    }
}
int main(){
    int i,x,y,z;
    scanf("%d%d",&n,&k);
    for(i=1;i<n;++i){
        scanf("%d%d%d",&x,&y,&z);
        make_al(x,y,z);
        make_al(y,x,z);
    }
    for(i=1;i<=k;++i)scanf("%d",b+i),chk[b[i]]=1;
    make_tree(1);
    printf("%lld %d",sum*2,ans+1);
    return 0;
}
