#include <stdio.h>
char c[60][60];
int a[60][60],chk[60][60],n,m,er,ec;
struct data{
    int r,c,d;
}q[6250010];
int f,r=1;
int x[]={-1,0,1,0},y[]={0,1,0,-1};
void ff(){
    int i,j,k,nr,nc;
    while(f<r){
        ++f;
        if(q[f].r==er&&q[f].c==ec){
            printf("%d",q[f].d-1);
            return;
        }
        if(q[f].d>q[f-1].d){
            for(i=1;i<=n;++i){
                for(j=1;j<=m;++j)if(a[i][j]==q[f].d){
                    for(k=0;k<4;++k){
                        nr=i+x[k],nc=j+y[k];
                        if((nr==er&&nc==ec)||a[nr][nc])continue;
                        a[nr][nc]=a[i][j]+1;
                    }
                }
            }
        }
        for(i=0;i<4;++i){
            nr=q[f].r+x[i],nc=q[f].c+y[i];
            if(nr<1||nr>n||nc<1||nc>m||a[nr][nc]||chk[nr][nc])continue;
            q[++r]={nr,nc,q[f].d+1};
            chk[nr][nc]=1;
        }
    }
    puts("impossible");
}
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        scanf("%s",c[i]+1);
        for(j=1;j<=m;++j){
            if(c[i][j]=='*')a[i][j]=1;
            if(c[i][j]=='X')a[i][j]=-1;
            if(c[i][j]=='D')er=i,ec=j;
            if(c[i][j]=='S')q[1]={i,j,1},chk[i][j]=1;
        }
    }
    ff();
    return 0;
}
