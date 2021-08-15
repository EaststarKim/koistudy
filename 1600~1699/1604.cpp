#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100010],D[100010],ans;
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=n;++i)ans=max(ans,D[i]=(a[i-1]<a[i])*D[i-1]+1);
    printf("%d",ans);
    return 0;
}
