#include <stdio.h>
#include <algorithm>
using namespace std;
int v[100010],d;
long long t[100010];
long long f(int s,int e,int l,int r){
    if(s>e||l>r)return 0;
    int i,p=0,m=(s+e)/2;
    long long ans=0;
    for(i=max(l,m-d);i<=min(m,r);++i)if(ans<(m-i)*t[m]+v[i])ans=(m-i)*t[m]+v[i],p=i;
    return max(ans,max(f(s,m-1,l,p),f(m+1,e,p,r)));
}
int main(){
    int i,n;
    scanf("%d%d",&n,&d);
    for(i=1;i<=n;++i)scanf("%lld",t+i);
    for(i=1;i<=n;++i)scanf("%d",v+i);
    printf("%lld",f(1,n,1,n));
    return 0;
}
