#include <stdio.h>
int a[110],b[110],c[110],t[20][110],n,bn,cn,cnt;
int s[]={1,1,2,1},d[]={1,2,2,3};
void f(){
    int i,j,k;
    for(i=1;i<bn;++i)if(!a[b[i]])return;
    for(i=1;i<cn;++i)if(a[c[i]])return;
    for(i=1;i<=cnt;++i){
        for(j=1;j<=n&&t[i][j]==a[j];++j);
        if(!a[j])break;
    }
    for(j=++cnt;j>i;--j)for(k=1;k<=n;++k)t[j][k]=t[j-1][k];
    for(j=1;j<=n;++j)t[i][j]=a[j];
}
int main(){
    int i,j,k,m;
    scanf("%d%d",&n,&m);
    do{scanf("%d",&b[++bn]);}while(b[bn]>0);
    do{scanf("%d",&c[++cn]);}while(c[cn]>0);
    for(i=0;i<16;++i){
        k=m-__builtin_popcount(i);
        if(k>=0&&k%2==0){
            for(k=1;k<=n;++k)a[k]=1;
            for(j=0;j<4;++j)if(i&(1<<j))for(k=s[j];k<=n;k+=d[j])a[k]=!a[k];
            f();
        }
    }
    for(i=1;i<=cnt;++i){
        for(j=1;j<=n;++j)printf("%d",t[i][j]);
        puts("");
    }
    if(!cnt)puts("IMPOSSIBLE");
    return 0;
}
