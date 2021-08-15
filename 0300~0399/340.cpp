#include <stdio.h>
#include <algorithm>
using namespace std;
const int MX=1e8;
struct data{
    int x,y;
}a[1010];
int w,D[1010][1010],ans=MX;
int main()
{
    int i,j,n,d;
    scanf("%d%d",&n,&w);
    for(i=1;i<=w;++i)scanf("%d%d",&a[i].x,&a[i].y);
    a[0].x=a[0].y=1;
    a[i].x=a[++w].y=n;
    for(i=0;i<=w;++i){
        for(j=0;j<=w;++j)D[i][j]=MX;
    }
    D[0][w]=0;
    for(i=1;i<w;++i){
        for(j=0;j<=w;++j){
            if(D[i-1][j]!=MX){
                D[i][j]=min(D[i][j],D[i-1][j]+abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y));
                D[i-1][i]=min(D[i-1][i],D[i-1][j]+abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y));
            }
            if(D[j][i-1]!=MX){
                D[j][i]=min(D[j][i],D[j][i-1]+abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y));
                D[i][i-1]=min(D[i][i-1],D[j][i-1]+abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y));
            }
        }
    }
    for(i=0;i<=w;++i)ans=min(ans,min(D[w-1][i],D[i][w-1]));
    printf("%d\n",ans);
    return 0;
}
