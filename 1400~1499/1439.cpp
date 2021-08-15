#include <stdio.h>
#include <algorithm>
using namespace std;
int a[51][51];
long long d[51][51][51][51];
long long f(int sr,int er,int sc,int ec){
    long long &s=d[sr][er][sc][ec];
    if(s)return s;
    if(sr==er&&sc==ec)return 0;
    int i;
    s=1e9;
    for(i=sr+1;i<=er;++i)s=min(s,f(sr,i-1,sc,ec)+f(i,er,sc,ec));
    for(i=sc+1;i<=ec;++i)s=min(s,f(sr,er,sc,i-1)+f(sr,er,i,ec));
    return s+=a[er][ec]-a[sr-1][ec]-a[er][sc-1]+a[sr-1][sc-1];
}
int main(){
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            scanf("%d",a[i]+j);
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    printf("%lld",f(1,n,1,m));
    return 0;
}
