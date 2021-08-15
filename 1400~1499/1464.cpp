#include <stdio.h>
#include <algorithm>
using namespace std;
int a[10000010];
long long D[10000010],E[10000010],ans;
long long delivery(int n,int k,int l){
    int i;
    sort(a,a+n);
    for(i=0;i<n;++i)D[i]=(i<k?0:D[i-k])+min(a[i]*2,l);
    for(;i--;)E[i]=(i<n-k?E[i+k]:0)+min((l-a[i])*2,l);
    ans=E[0];
    for(i=0;i<n;++i)ans=min(ans,D[i]+E[i+1]);
    return ans;
}
int main(){
    int i,n,k,l;
    scanf("%d%d%d",&n,&k,&l);
    for(i=0;i<n;++i)scanf("%d",a+i);
    printf("%lld",delivery(n,k,l));
    return 0;
}
