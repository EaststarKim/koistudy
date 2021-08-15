#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100010],b[100010];
int main(){
    int i,n,k,s=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i),b[i]=a[i];
    sort(b+1,b+n+1);
    for(i=1;i<=n;++i)a[i]=lower_bound(b+1,b+n+1,a[i])-b;
    for(i=1;i<=n;++i)s+=(i%2!=a[i]%2);
    printf("%d",s/2);
    return 0;
}
