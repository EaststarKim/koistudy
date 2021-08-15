#include <stdio.h>
int a[1299710];
int main()
{
    int i,j,k;
    scanf("%d",&k);
    for(i=2;k;++i)if(!a[i]){
        --k;
        for(j=i*2;j<1299709;j+=i)a[j]=1;
    }
    printf("%d",i-1);
    return 0;
}
