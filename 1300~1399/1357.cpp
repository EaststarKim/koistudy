#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1000010];
int main(){
    int i,j,n,t;
    scanf("%d%d",&n,&t);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    sort(a+1,a+n+1);
    if(t<2)for(i=n;i;--i)printf("%d ",a[i]);
    else for(i=1;i<=n;++i)printf("%d ",a[i]);
    return 0;
}
