#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int D[2000010],j,m;
char a[2000010];
long long ans;
int main(){
    int i,n;
    scanf("%s",a+1);
    n=strlen(a+1);
    for(i=n;i;--i)a[i*2]=a[i],a[i*2-1]='#';
    n*=2;
    a[n+1]='#';
    for(i=1;i<=n;++i){
        if(i<=m)D[i]=min(D[2*j-i],m-i);
        while(i>D[i]&&a[i-D[i]-1]==a[i+D[i]+1])++D[i];
        if(m<i+D[i])m=i+D[i],j=i;
        ans+=D[i]/2;
    }
    printf("%lld",ans+n/2);
    return 0;
}
