#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a[500010];
int q[500010],r;
int st[500010][19],lev[500010];
void bfs(int p){
    int i;
    for(i=1;i<19;++i)st[p][i]=st[st[p][i-1]][i-1];
    for(i=0;i<a[p].size();++i)q[++r]=a[p][i],lev[a[p][i]]=lev[p]+1;
}
int LCA(int x,int y){
    int i;
    if(lev[x]<lev[y])swap(x,y);
    for(i=18;i>=0;--i)if(lev[x]-lev[y]>=1<<i)x=st[x][i];
    if(x==y)return x;
    for(i=18;i>=0;--i)if(st[x][i]!=st[y][i])x=st[x][i],y=st[y][i];
    return st[x][0];
}
int main(){
    int i,n,t,x,y;
    long long ans;
    scanf("%d",&n);
    for(i=2;i<=n;++i){
        scanf("%d",st[i]);
        a[st[i][0]].push_back(i);
    }
    q[r=1]=1;
    for(i=1;i<=r;++i)bfs(q[i]);
    scanf("%d",&t);
    for(;t--;){
        scanf("%d%d",&x,&y);
        int lca=LCA(x,y);
        if(lca==1)printf("rm %d rm %d\n",x,y);
        else printf("rmdir %d\n",lca);
    }
    return 0;
}
