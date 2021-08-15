#include <stdio.h>
#include <algorithm>
using namespace std;
#define M 1043
int x[1000010],y[1000010],t[1000010];
int a[1010][1010],D[1010][1010];
int main(){
    int i,j,k,w,h,n;
    scanf("%d%d%d",&h,&w,&n);
    for(i=1;i<n;++i)scanf("%d%d",x+i,y+i);
    x[0]=y[0]=1,x[n]=h,y[n]=w;
    for(i=1;i<=n;++i)scanf("%d",t+i),t[i]+=t[i-1];
    for(i=1;i<=h;++i){
        for(j=1;j<=w;++j)scanf("%d",a[i]+j);
    }
    for(i=0;i<=h;++i){
        for(j=0;j<=w;++j)D[i][j]=1e9;
    }
    D[1][1]=0;
    for(k=0;k<n;++k){
        for(i=x[k];i<=x[k+1];++i){
            for(j=y[k];j<=y[k+1];++j)if(i!=x[k]||j!=y[k]){
                D[i][j]=min(D[i-1][j],D[i][j-1])+a[i][j];
            }
        }
        if(D[x[k+1]][y[k+1]]>t[k+1]){
            puts("-1");
            return 0;
        }
    }
    printf("%d %d",(t[n]-D[h][w]%M+M)%M,D[h][w]%M);
    return 0;
}
