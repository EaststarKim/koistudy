#include <stdio.h>
long long a[100010]={0,0,1,8,40},M=1e9;
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=5;i<=n;++i)a[i]=(a[i-1]+a[i-2])*4%M;
    printf("%d",a[n]);
    return 0;
}
