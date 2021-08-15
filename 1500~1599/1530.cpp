#include <stdio.h>
#include <algorithm>
using namespace std;
int a[41][4];
int main(){
    int i,n;
    scanf("%d",&n);
    a[1][2]=a[2][1]=a[2][0]=1;
    for(i=3;i<=n;++i){
        a[i][0]=a[i-1][2];
        a[i][1]=a[i-2][0]+a[i-2][2];
        a[i][2]=a[i-1][1]+a[i-1][3];
        a[i][3]=a[i-2][1];
    }
    printf("%d",a[n][0]+a[n][1]+a[n][2]+a[n][3]);
    return 0;
}
