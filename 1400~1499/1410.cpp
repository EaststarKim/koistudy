#include <stdio.h>
#include <algorithm>
using namespace std;
int a[110];
int main(){
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=m;++i){
        for(j=1;j<n;++j)if(a[j]%i>a[j+1]%i)swap(a[j],a[j+1]);
    }
    for(i=1;i<=n;++i)printf("%d ",a[i]);
    return 0;
}
