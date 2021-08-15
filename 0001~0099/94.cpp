#include <stdio.h>
int main()
{
    int i,n,k,mn=24;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&k);
        if(mn>k)mn=k;
    }
    printf("%d",mn);
}
