#include <stdio.h>
#include <algorithm>
using namespace std;
long long x[100010];
int main(){
    int i,j,n,l,r,m,ans;
    long long b,mn;
    scanf("%d%d%lld",&n,&l,&b);
    for(i=1;i<=n;++i)scanf("%lld",x+i),x[i]+=x[i-1];
    l=1,r=n;
    while(l<=r){
        m=(l+r)/2;
        mn=1e18;
        for(i=1;i<=n-m+1;++i){
            j=i+m/2;
            mn=min(mn,(x[i+m-1]-x[j])-(x[j]-x[j-1])*(i+m-1-j)+(x[j]-x[j-1])*(j-i)-(x[j-1]-x[i-1]));
        }
        if(mn>b)r=m-1;
        else l=m+1,ans=m;
    }
    printf("%d",ans);
    return 0;
}
