#include <bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
long long ans;
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=n;++i)scanf("%d",b+i);
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for(i=j=n;i;--i)if(a[i]<b[j])ans+=b[j--];
    printf("%lld",ans);
    return 0;
}
