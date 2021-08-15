#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
struct data{
    int x,y;
}a[100010];
int D[2][100010];
int d(int i,int j){return abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);}
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y),D[1][i]=1e9;
    for(i=2;i<=n;++i){
        D[0][i]=D[0][i-1]+d(i,i-1);
        D[1][i]=min(D[1][i],D[1][i-1]+d(i,i-1));
        if(i>2)D[1][i]=min(D[1][i],D[0][i-2]+d(i,i-2));
    }
    printf("%d",D[1][n]);
    return 0;
}
