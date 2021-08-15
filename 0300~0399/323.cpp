#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
vector<int> mat[5010];
int left[5010],right[5010],ld[110][110],rd[110][110],visit[5010],n,ans,ln,rn;
int f(int v,int& cnt){
    return v>0? v:++cnt;
}
void make(){
    int i,j;
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)if(ld[i][j]>=0){
            ld[i][j]=f(ld[i-1][j-1], ln);
            rd[i][j]=f(rd[i-1][j+1], rn);
            mat[ld[i][j]].push_back(rd[i][j]);
        }
    }
}
int augment(int i){
    for(int j=0;j<(signed)mat[i].size();++j){
        int next=mat[i][j];
        if(!visit[next]){
            visit[next]=1;
            if(!right[next]||augment(right[next])){
                left[i]=next;
                right[next]=i;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int i,m,r,c;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i){
        scanf("%d%d",&r,&c);
        ld[r][c]=rd[r][c]=-1;
    }
    make();
    for(i=1;i<=ln;++i){
        memset(visit,0,sizeof(visit));
        ans+=augment(i);
    }
    printf("%d",ans);
    return 0;
}
