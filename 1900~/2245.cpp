#include <bits/stdc++.h>
using namespace std;
struct data{
    int a,p;
    bool operator<(const data&r)const{
        return a*r.p<r.a*p;
    }
}a[200010];
long long s,ans;
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].a,&a[i].p),s+=a[i].a;
    sort(a+1,a+n+1);
    for(i=1;i<=n;++i)ans+=a[i].p*s,s-=a[i].a;
    printf("%lld",ans);
    return 0;
}
