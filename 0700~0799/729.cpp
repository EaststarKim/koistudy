#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[510][510],chk[510][510],q[125010][2],n;
int x[]={-1,0,1,0},y[]={0,1,0,-1};
int bfs(int r,int c,int d){
    int i,nr,nc,f=0,t=1;
    q[1][0]=r,q[1][1]=c;
    chk[r][c]=1;
    while(f<t){
        r=q[++f][0],c=q[f][1];
        for(i=0;i<4;++i){
            nr=r+x[i],nc=c+y[i];
            if(nr<1||nr>n||nc<1||nc>n||chk[nr][nc]||abs(a[r][c]-a[nr][nc])>d)continue;
            chk[nr][nc]=1;
            q[++t][0]=nr,q[t][1]=nc;
        }
        if(t*2>=n*n)return 1;
    }
    return 0;
}
int f(int d){
    int i,j;
    memset(chk,0,sizeof chk);
    for(i=1;i<=n;++i)for(j=1;j<=n;++j)if(!chk[i][j]&&bfs(i,j,d))return 1;
    return 0;
}
int main(){
    int i,j,l=0,r=1e6,m,ans;
    scanf("%d",&n);
    for(i=1;i<=n;++i)for(j=1;j<=n;++j)scanf("%d",a[i]+j);
    while(l<=r){
        m=(l+r)/2;
        if(f(m))ans=m,r=m-1;
        else l=m+1;
    }
    printf("%d",ans);
    return 0;
}
