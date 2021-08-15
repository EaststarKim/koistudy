#include <stdio.h>
#include <algorithm>
using namespace std;
long long a[50010];
int s[7],e[7],ans;
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%lld",a+i),a[i]+=a[i-1];
        if(!s[a[i]%7])s[a[i]%7]=i;
        e[a[i]%7]=i;
    }
    for(i=0;i<7;++i)ans=max(ans,e[i]-s[i]);
    printf("%d",ans);
    return 0;
}
