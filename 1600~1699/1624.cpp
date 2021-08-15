#include <stdio.h>
#include <algorithm>
using namespace std;
long long x[510],y[510],ans;
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%lld%lld",x+i,y+i);
    for(i=1;i<n;++i){
        for(j=i+1;j<=n;++j)ans=max(ans,((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+3)/4);
    }
    for(i=1;i<n-1;++i){
        for(j=i+1;j<n;++j){
            for(k=j+1;k<=n;++k){
                long long a=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]),b=(x[j]-x[k])*(x[j]-x[k])+(y[j]-y[k])*(y[j]-y[k]),c=(x[k]-x[i])*(x[k]-x[i])+(y[k]-y[i])*(y[k]-y[i]);
                if(a>b+c||b>c+a||c>a+b)continue;
                long long s=x[i]*(y[j]-y[k])+x[j]*(y[k]-y[i])+x[k]*(y[i]-y[j]);
                if(!s)continue;
                s=s*s*4;
                ans=max(ans,(a*b*c+s-1)/s);
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
