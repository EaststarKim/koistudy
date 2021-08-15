#include <stdio.h>
#include <algorithm>
using namespace std;
char c[2010][2010];
int a[2010][2010],b[2010][2010];
long long ans;
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%s",c[i]+1);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)a[i][j]=(c[i][j]=='#')?a[i][j-1]+1:0;
        for(j=n;j;--j)b[i][j]=(c[i][j]=='#')?b[i][j+1]+1:0;
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)a[i][j]=min(a[i][j],b[i][j]);
    }
    for(j=1;j<=n;++j){
        k=0;
        for(i=1;i<=n;++i){
            if(k<a[i][j])++k;
            else ans+=k*(k+1)/2-a[i][j]*(a[i][j]-1)/2,k=a[i][j];
        }
        ans+=k*(k+1)/2;
    }
    printf("%lld",ans);
    return 0;
}
