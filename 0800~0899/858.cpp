#include <stdio.h>
#include <vector>
using namespace std;
vector<int> v[1000010];
int q[1000010],chk[1000010],n,x,y;
int BFS(int k){
    int i,p,f=0,r=1,t,s;
    for(i=1;i<=n;++i)chk[i]=0;
    q[1]=k;
    chk[k]=1;
    while(f<r){
        p=q[++f];
        if(p!=k&&(p==x||p==y))return 1;
        t=v[p].size();
        for(i=0;i<t;++i){
            s=v[p][i];
            if(!chk[s])chk[q[++r]=s]=1;
        }
    }
    return 0;
}
int main()
{
    int i,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i){
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
    }
    scanf("%d%d",&x,&y);
    if(BFS(x))puts("yes");
    else if(BFS(y))puts("no");
    else puts("unknown");
    return 0;
}
