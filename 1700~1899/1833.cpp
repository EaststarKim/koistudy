#include <bits/stdc++.h>
using namespace std;
int a[20][100010],D[1048580],l[1048580];
int main(){
    int i,j,n,m,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        scanf("%d",&k);
        a[k-1][i]=1;
        for(j=0;j<m;++j)a[j][i]+=a[j][i-1];
    }
    k=1<<m;
    for(i=1;i<k;++i){
        D[i]=1e9;
        for(j=0;j<m;++j)if(i&(1<<j))l[i]+=a[j][n];
        for(j=0;j<m;++j)if(i&(1<<j))D[i]=min(D[i],D[i^(1<<j)]+a[j][n]-a[j][l[i]]+a[j][l[i]-a[j][n]]);
    }
    printf("%d",D[k-1]);
    return 0;
}
