#include <stdio.h>
#include <algorithm>
using namespace std;
int a[200010];
int main(){
    int i,n,m,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%d",a+i),a[i]=-a[i];
    sort(a+1,a+n+1);
    for(i=1;i<=m;++i){
        scanf("%d",&k);
        printf("%d ",n+1-(lower_bound(a+1,a+n+1,-k)-a));
    }
    return 0;
}
