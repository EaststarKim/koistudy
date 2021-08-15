#include <stdio.h>
#include <algorithm>
using namespace std;
int w[210],h[210],D[610][610],n;
int f(int W,int H){
    int i;
    if(D[W][H]<1e6)return D[W][H];
    D[W][H]=W*H;
    for(i=1;i<=n;++i)if(w[i]<=W&&h[i]<=H)D[W][H]=min(D[W][H],min(f(W-w[i],H)+f(w[i],H-h[i]),f(W,H-h[i])+f(W-w[i],h[i])));
    return D[W][H];
}
int main(){
    int i,j,W,H;
    scanf("%d%d%d",&W,&H,&n);
    for(i=1;i<=n;++i)scanf("%d%d",w+i,h+i);
    for(i=1;i<=W;++i){
        for(j=1;j<=H;++j)D[i][j]=1e6;
    }
    printf("%d",f(W,H));
    return 0;
}
