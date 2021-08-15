#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1000010];
int main(){
    int i,j,n,m,k;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    scanf("%d",&m);
    for(i=1;i<=m;++i){
        scanf("%d",&k);
        j=lower_bound(a+1,a+n+1,k)-a;
        if(a[j]!=k)j=-1;
        printf("%d ",j);
    }
    return 0;
}
