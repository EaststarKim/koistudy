#include <stdio.h>
#include <algorithm>
using namespace std;
long long a[200010],s[100010],D[200010];
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n*2;++i){
        D[i]=D[i-1];
        scanf("%d",a+i);
        if(!s[a[i]])s[a[i]]=i;
        else D[i]=max(D[i],D[s[a[i]]-1]+a[i-1]+a[i]-a[s[a[i]]-1]);
        a[i]+=a[i-1];
    }
    printf("%lld",D[n*2]);
    return 0;
}
