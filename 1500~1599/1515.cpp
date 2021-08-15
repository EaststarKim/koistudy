#include <stdio.h>
#include <algorithm>
using namespace std;
char c[15010][1510];
int a[15010][1510],b[1510],t[1510],ans;
int main(){
    int i,j,n,m,f,r;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%s",c[i]+1);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)a[i][j]=(c[i][j]=='1')*(a[i-1][j]+1);
    }
    for(i=1;i<=m;++i)b[i]=i;
    for(i=1;i<=n;++i){
        f=1,r=m;
        for(j=1;j<=m;++j){
            if(a[i][b[j]])t[f++]=b[j];
            else t[r--]=b[j];
        }
        for(j=1;j<=m;++j)b[j]=t[j];
        for(j=1;j<=m;++j)ans=max(ans,a[i][b[j]]*j);
    }
    printf("%d",ans);
    return 0;
}
