#include <stdio.h>
struct al{
    int e,nx;
}a[4410010];
int st[2110],chk[2110][2110],sz[2110],cnt,t;
void make_al(int s,int e){a[++t]={e,st[s]},st[s]=t;}
void dfs(int s,int n){
    int i;
    ++sz[s];
    chk[s][n]=1;
    for(i=st[n];i;i=a[i].nx)if(!chk[s][a[i].e])dfs(s,a[i].e);
}
int main(){
    int i,j,n,k,x,ans=1;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            scanf("%d",&x);
            if(!x)make_al(j,i);
        }
    }
    for(i=1;i<=n;++i)dfs(i,i);
    for(i=1;i<=n;++i)if(chk[i][k]){
        for(j=1;j<i;++j)if(chk[j][i]&&sz[i]==sz[j])break;
        if(j==i&&sz[i]<n)++ans;
    }
    printf("%d",ans);
    return 0;
}
