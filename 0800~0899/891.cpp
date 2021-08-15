#include <stdio.h>
#include <algorithm>
using namespace std;
char c[5010][5010];
int a[5010][5010],b[5010],t[5010],ans;
int main(){
    int i,j,n,m,f,r;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%s",c[i]+1);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)a[i][j]=(c[i][j]=='1')*(a[i][j-1]+1);
    }
    for(i=1;i<=n;++i)b[i]=i;
    for(i=1;i<=m;++i){
        f=1,r=n;
        for(j=1;j<=n;++j){
            if(a[b[j]][i])t[f++]=b[j];
            else t[r--]=b[j];
        }
        for(j=1;j<=n;++j)b[j]=t[j];
        for(j=1;j<=n;++j)ans=max(ans,a[b[j]][i]*j);
    }
    printf("%d",ans);
    return 0;
}
