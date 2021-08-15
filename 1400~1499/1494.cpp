#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int a[110];
int main(){
    int i,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)scanf("%d%d",a+i,a+i);
    sort(a+1,a+m+1);
    long long ans=0;
    for(i=1;i<=m;++i)ans+=abs(a[i]-a[(m+1)/2]);
    printf("%lld",ans);
    return 0;
}
