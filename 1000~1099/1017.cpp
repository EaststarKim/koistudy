#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int i,j,H,W,h,w,ans=0;
    scanf("%d%d%d%d",&H,&W,&h,&w);
    int a[H+1][W+1];
    for(i=0;i<=W;++i)a[0][i]=0;
    for(i=0;i<=H;++i)a[i][0]=0;
    for(i=1;i<=H;++i){
        for(j=1;j<=W;++j){
            scanf("%d",a[i]+j);
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    --h;
    --w;
    H-=h;
    W-=w;
    for(i=1;i<=H;++i){
        for(j=1;j<=W;++j)ans=max(ans,a[i+h][j+w]-a[i-1][j+w]-a[i+h][j-1]+a[i-1][j-1]);
    }
    printf("%d",ans);
    return 0;
}
