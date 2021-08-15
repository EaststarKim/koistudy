#include <bits/stdc++.h>
using namespace std;
int a[310],D[310][310][2],ans;
int main(){
    int i,j,k,l,n,m,t;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    sort(a,a+n+1);
    for(t=0;t<=n;++t)if(!a[t])break;
    for(i=1;i<=n;++i){
        for(j=0;j<=n;++j){
            for(k=0;k<=n;++k)D[j][k][0]=D[j][k][1]=1e9;
        }
        D[t][t][0]=0;
        for(j=0;j<i;++j){
            for(k=0;k<=n-j;++k)if(k<=t&&t<=k+j){
                for(l=0;l<2;++l)if(D[k][k+j][l]<1e9){
                    if(k)D[k-1][k+j][0]=min(D[k-1][k+j][0],D[k][k+j][l]+(i-j)*(a[k+j*l]-a[k-1]));
                    if(k+j<n)D[k][k+j+1][1]=min(D[k][k+j+1][1],D[k][k+j][l]+(i-j)*(a[k+j+1]-a[k+j*l]));
                }
            }
        }
        for(k=0;k<=n-i;++k)if(k<=t&&t<=k+i)ans=max(ans,m*i-min(D[k][k+i][0],D[k][k+i][1]));
    }
    printf("%d",ans);
    return 0;
}
