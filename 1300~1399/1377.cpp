#include <stdio.h>
const int M=1e9+7;
int a[1300000]={0,1};
int main(){
    int i,t,n;
    for(i=2;i<=1234567;++i)a[i]=(a[i-1]+a[i-2])%M;
    for(i=3;i<1234567;i+=3)a[i]=(a[i]+a[i-3])%M;
    scanf("%d",&t);
    for(;t--;){
        scanf("%d",&n);
        printf("%d\n",a[n/3*3]);
    }
    return 0;
}
