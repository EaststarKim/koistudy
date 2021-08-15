#include <stdio.h>
#include <algorithm>
using namespace std;
double a[2500010],s;
int main(){
    int i,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%lf",a+i);
    sort(a+1,a+n+1);
    for(i=n;i>n-m;--i)s+=a[i];
    printf("%.4lf",s);
    return 0;
}
