#include <stdio.h>
#include <algorithm>
using namespace std;
int D[41]={1,1},E[41]={0,1},ans,cnt;
int main(){
    int i,n,k;
    scanf("%d%d",&n,&k);
    for(i=2;i<=n;++i)D[i]=D[i-1]+D[i-2];
    for(i=2;i<=n;++i)E[i]=D[i-1]+E[i-1];
    ans=D[k-1]*D[n-k];
    for(i=1;i<k;++i)cnt+=D[i-1]*D[k-i-1]+E[i-1]*D[k-i-1]+D[i-1]*E[k-i-1];
    ans+=cnt*D[n-k];
    cnt=0;
    for(i=1;i<=n-k;++i)cnt+=D[i-1]*D[n-k-i]+E[i-1]*D[n-k-i]+D[i-1]*E[n-k-i];
    ans+=cnt*D[k-1];
    printf("%d",ans);
    return 0;
}
