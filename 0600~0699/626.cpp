#include <stdio.h>
int a[2][64],chk[64],D[100010][64],ans;
void dfs(int p){
    int i,s;
    if(chk[p])return;
    chk[p]=1;
    for(i=s=0;i<6;++i)if(p&(1<<i))a[0][p]|=a[0][1<<i];
    dfs(a[0][p]);
    for(i=s=0;i<6;++i)if(p&(1<<i))a[1][p]|=a[1][1<<i];
    dfs(a[1][p]);
}
int main(){
    int i,j,n;
    scanf("%d",&n);
    a[1][1]=6;
    a[0][2]=5,a[1][2]=8;
    a[0][4]=17;
    a[1][8]=2;
    a[0][16]=54,a[1][16]=8;
    a[0][32]=16,a[1][32]=34;
    for(i=0;i<6;++i)dfs(1<<i);
    D[0][1]=1;
    for(i=0;i<n;++i){
        for(j=1;j<64;++j){
            D[i+1][a[0][j]]+=D[i][j],D[i+1][a[1][j]]+=D[i][j];
        }
        for(j=1;j<64;++j)D[i+1][j]%=1000003;
    }
    for(i=1;i<64;++i)if(i&44)ans=(ans+D[n][i])%1000003;
    printf("%d",ans);
    return 0;
}
