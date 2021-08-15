#include <stdio.h>
int a[20][20],n,M;
long long D[1<<17][20],ans;
long long f(int s,int t){
    int i;
    if(s==M)return 1;
    if(D[s][t])return D[s][t];
    for(i=2;i<=n;++i)if(a[t][i]&&!(s&(1<<(i-2))))D[s][t]+=f(s+(1<<(i-2)),i);
    return D[s][t];
}
int main(){
    int i,j,k,m,x,y;
    scanf("%d%d",&n,&m);
    M=(1<<(n-1))-1;
    for(i=1;i<=m;++i){
        scanf("%d%d",&x,&y);
        a[x][y]=a[y][x]=1;
    }
    printf("%lld",f(0,1));
    return 0;
}
