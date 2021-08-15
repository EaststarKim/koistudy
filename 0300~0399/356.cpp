#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
struct data{
    int i,d;
    bool operator<(const data&r)const{
        return d<r.d;
    }
}a[510];
int x[510],y[510],ans=1e4;
int d[510][510];
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",x+i,y+i);
    for(i=1;i<n;++i){
        for(j=i+1;j<=n;++j)d[i][j]=d[j][i]=abs(x[i]-x[j])+abs(y[i]-y[j]);
    }
    for(i=1;i<n;++i){
        for(j=1;j<=n;++j)a[j]={j,d[i][j]};
        sort(a+1,a+n+1);
        for(j=i+1;j<=n;++j){
            ans=min(ans,a[n].d+a[n-1].d);
            int s=a[n].i,t=0;
            for(k=n;k;--k) {
                if(d[j][s]<d[j][a[k].i])t=s,s=a[k].i;
                else if(!t||d[j][t]<d[j][a[k].i])t=a[k].i;
                if(k<2){
                    ans=min(ans,d[j][s]+d[j][t]);
                    break;
                }
                int mn=a[k-1].d+d[i][j]+d[j][s];
                if(k>2)mn=max(mn,a[k-1].d+a[k-2].d);
                if(t)mn=max(mn,d[j][s]+d[j][t]);
                ans=min(ans,mn);
            }
        }
    }
    printf("%d",ans);
    return 0;
}
