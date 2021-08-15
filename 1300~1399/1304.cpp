#include <stdio.h>
#include <algorithm>
using namespace std;
int a[3510][3510],c[3510][3510],D[810][3510];
int get(){
    char c=getchar();
    while(c<48)c=getchar();
    return c-48;
}
void opt(int k,int s,int e,int l,int r){
    if(s>e||l>r)return;
    int i,p=0,m=(s+e)/2;
    D[k][m]=1e9;
    for(i=l;i<min(m,r+1);++i)if(D[k-1][i]+c[i+1][m]<D[k][m])D[k][m]=D[k-1][i]+c[i+1][m],p=i;
    opt(k,s,m-1,l,p);
    opt(k,m+1,e,p,r);
}
int main(){
    int i,j,n,k;
    scanf("%d%d\n",&n,&k);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)a[i][j]=get();
    }
    for(j=1;j<=n;++j){
        for(i=j;--i;)c[i][j]=c[i+1][j]+c[i][j-1]-c[i+1][j-1]+a[i][j];
    }
    for(i=1;i<=n;++i)D[1][i]=c[1][i];
    for(i=2;i<=k;++i)opt(i,1,n,1,n);
    printf("%d",D[k][n]);
    return 0;
}
