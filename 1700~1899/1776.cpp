#include <stdio.h>
#include <algorithm>
using namespace std;
char c[1000010];
int a[1000010],b[1000010];
int main(){
    int i,n,s,t;
    scanf("%d%s",&n,c+1);
    for(i=1;i<=n;++i){
        b[i]=b[i-1]+(c[i]=='A');
        a[i]=a[i-1]+(c[i]=='B');
        a[i]=min(a[i],b[i]+1);
        b[i]=min(b[i],a[i]+1);
    }
    printf("%d",a[n]);
    return 0;
}
