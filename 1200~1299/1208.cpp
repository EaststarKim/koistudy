#include <stdio.h>
char a[1010][1010],b[1010][1010];
int q[8000010][2],f,r,p,t;
int x[]={-1,-1,0,1,1,1,0,-1},y[]={0,1,1,1,0,-1,-1,-1};
int main(){
    int i,j,k,n,m,nr,nc;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%s",a[i]+1);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)if(a[i][j]!='.'){
            for(k=0;k<8;++k)b[i][j]+=(a[i+x[k]][j+y[k]]=='.');
            if(b[i][j]>=a[i][j]-48)q[++r][0]=i,q[r][1]=j;
        }
    }
    while(f<r){
        i=q[++f][0],j=q[f][1];
        if(f>p)++t,p=r;
        for(k=0;k<8;++k)if(a[i][j]!='.'){
            nr=i+x[k],nc=j+y[k];
            ++b[nr][nc];
            if(b[nr][nc]==a[nr][nc]-48)q[++r][0]=nr,q[r][1]=nc;
        }
    }
    printf("%d",t);
    return 0;
}
