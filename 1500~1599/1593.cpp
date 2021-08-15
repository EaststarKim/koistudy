#include <stdio.h>
int a[110][110],chk[110][110],n,m,ans=1e5;
int x[]={0,1,0,-1},y[]={1,0,-1,0};
void f(int r,int c,int s=0){
    if(s>=ans)return;
    if(r<1||r>n||c<1||c>m||chk[r][c])return;
    if(a[r][c]>3){
        ans=s;
        return;
    }
    chk[r][c]=1;
    int nr=r+x[a[r][c]],nc=c+y[a[r][c]];
    f(nr,nc,s+1);
    chk[r][c]=0;
}
int main(){
    int i,j;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)scanf("%d",a[i]+j);
    }
    for(i=1;i<=n;++i)f(i,1),f(i,m);
    for(i=1;i<=m;++i)f(1,i),f(n,i);
    if(ans>1e4)ans=-1;
    printf("%d",ans);
    return 0;
}
