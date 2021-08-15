#include <bits/stdc++.h>
using namespace std;
long long a[300010],b[300010],ans;
int bit[300010],n;
int getsum(int k){
    int s=0;
    for(;k;k-=k&-k)s+=bit[k];
    return s;
}
void update(int k){for(;k<=n+1;k+=k&-k)++bit[k];}
int main(){
    int i,p;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%lld",a+i);
    scanf("%d",&p);
    for(i=1;i<=n;++i)a[i]+=a[i-1]-p,b[i]=a[i];
    sort(b,b+n+1);
    for(i=0;i<=n;++i)a[i]=lower_bound(b,b+n+1,a[i])-b+1;
    for(i=0;i<=n;++i)ans+=getsum(a[i]),update(a[i]);
    printf("%lld",ans);
    return 0;
}
