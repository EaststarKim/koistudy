#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1010],s[1010],D[1010][1010];
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",a+i);
        s[i]=s[i-1]+a[i];
    }
    for(i=n;i;--i){
        for(j=i;j<=n;++j)D[i][j]=s[j]-s[i-1]-min(D[i+1][j],D[i][j-1]);
    }
    printf("%d",D[1][n]);
    return 0;
}
