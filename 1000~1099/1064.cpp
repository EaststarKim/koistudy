#include <stdio.h>
int main()
{
    int i,n;
    scanf("%d",&n);
    for(;n>0;--n){
        for(i=0;i<n;++i)printf("*");
        puts("");
    }
    return 0;
}
