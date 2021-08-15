#include <stdio.h>
#include <algorithm>
using namespace std;
int a[20010],b[20010],s[20010],e[20010],p,mx;
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=n;++i){
        while(p&&a[b[p]]>=a[i])--p;
        s[i]=b[p]+1;
        b[++p]=i;
    }
    p=0;
    b[0]=n+1;
    for(i=n;i;--i){
        while(p&&a[b[p]]>=a[i])--p;
        e[i]=b[p]-1;
        b[++p]=i;
    }
    for(i=1;i<=n;++i)mx=max(mx,(e[i]-s[i]+1)*a[i]);
    printf("%d",mx);
    return 0;
}
