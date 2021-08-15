#include <stdio.h>
#include <algorithm>
using namespace std;
int a[200],b[200],c[200],D[1510][1510],ans;
int main(){
    int i,j,k,h,s,n;
    scanf("%d%d%d",&h,&s,&n);
    for(i=1;i<=n;++i)scanf("%d%d%d",a+i,b+i,c+i);
    D[h][s]=1;
    for(i=1;i<=n;++i){
        for(j=a[i];j<=h;++j){
            for(k=b[i];k<=s;++k)if(D[j][k])D[j-a[i]][k-b[i]]=max(D[j-a[i]][k-b[i]],D[j][k]+c[i]);
        }
    }
    for(i=0;i<=h;++i){
        for(j=0;j<=s;++j)ans=max(ans,D[i][j]);
    }
    if(ans<2)ans=0;
    printf("%d",ans-1);
    return 0;
}
