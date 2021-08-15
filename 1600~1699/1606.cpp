#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int x[110],y[110];
int main(){
    int i,j,k,n;
    double ans=1e9,s,t;
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%d%d",x+i,y+i);
    for(i=0;i<n;++i){
        for(j=0;j<i;++j){
            s=0,t=0;
            int a=y[j]-y[i],b=x[j]-x[i];
            for(k=0;k<n;++k){
                double p=(double)(a*(x[k]-x[i])-b*(y[k]-y[i])),q=sqrt((double)(a*a+b*b));
                s=max(s,p/q);
                t=min(t,p/q);
            }
            ans=min(ans,s-t);
        }
    }
    printf("%.2f",ans+0.005);
    return 0;
}
