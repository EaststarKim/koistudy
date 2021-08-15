#include <stdio.h>
int a[10000001]={0,2,7,22};
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=4;i<=n;++i){
        a[i]=(3*a[i-1]+a[i-2]-a[i-3])%1000000;
        if(a[i]<0)a[i]+=1000000;
    }
    printf("%d",a[n]);
    return 0;
}
