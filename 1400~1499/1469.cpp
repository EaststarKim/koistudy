#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int x,y;
}a[1010];
bool cmpx(data a,data b){return a.x<b.x;}
bool cmpy(data a,data b){return a.y<b.y;}
int s[1010][1010];
int main(){
    int i,j,n,cnt,ans,x,y,z,w;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+n+1,cmpx);
    a[1].x=cnt=1;
    for(i=2;i<=n;++i){
        if(a[i].x>a[i-1].x)++cnt;
        a[i].x=cnt;
    }
    sort(a+1,a+n+1,cmpy);
    a[1].y=cnt=1;
    for(i=2;i<=n;++i){
        if(a[i].y>a[i-1].y)++cnt;
        a[i].y=cnt;
    }
    for(i=1;i<=n;++i)s[a[i].x][a[i].y]=1;
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
    }
    ans=n;
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            x=s[i][j];
            y=s[i][n]-x;
            z=s[n][j]-x;
            w=n-x-y-z;
            ans=min(ans,max(x,max(y,max(z,w))));
        }
    }
    printf("%d",ans);
    return 0;
}
