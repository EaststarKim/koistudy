#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1000010],q[1000010],f,r;
int main(){
    int i,n,w;
    scanf("%d%d",&n,&w);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    f=1;
    for(i=1;i<=n;++i){
        while(f<=r&&a[q[r]]>=a[i])--r;
        q[++r]=i;
        if(q[f]<=i-w)++f;
        if(i>=w)printf("%d ",a[q[f]]);
    }
    puts("");
    f=1,r=0;
    for(i=1;i<=n;++i){
        while(f<=r&&a[q[r]]<=a[i])--r;
        q[++r]=i;
        if(q[f]<=i-w)++f;
        if(i>=w)printf("%d ",a[q[f]]);
    }
    return 0;
}
