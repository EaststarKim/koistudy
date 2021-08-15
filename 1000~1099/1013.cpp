#include <stdio.h>
#include <algorithm>
using namespace std;
int a[5010],D[2][5010],ans;
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    D[0][0]=D[1][0]=1;
    for(i=1;i<=n;++i){
        D[0][i]=D[1][0]+1;
        D[1][i]=D[0][0]+1;
        for(j=1;j<i;++j){
            if(a[i]<a[j])D[1][i]=max(D[1][i],D[0][j]+1);
            if(a[i]>a[j])D[0][i]=max(D[0][i],D[1][j]+1);
        }
    }
    for(i=1;i<=n;++i)ans=max(ans,max(D[0][i],D[1][i]));
    printf("%d",ans-1);
    return 0;
}
