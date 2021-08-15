#include <stdio.h>
#include <algorithm>
using namespace std;
char a[5010],b[5010];
int D[5010][5010];
int main(){
    int i,j,n;
    scanf("%d\n%s",&n,a+1);
    for(i=1;i<=n;++i)b[i]=a[n-i+1];
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)D[i][j]=max(D[i-1][j],max(D[i][j-1],D[i-1][j-1]+(a[i]==b[j])));
    }
    printf("%d",n-D[n][n]);
    return 0;
}
