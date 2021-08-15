#include <stdio.h>
int main()
{
    int i,n,k,a;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i){
        scanf("%d",&a);
        if(a>k)break;
    }
    printf("%d",i);
    return 0;
}
