#include <stdio.h>
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=n-1;i>=0;--i){
        for(j=1;j<1<<n;++j){
            if(j%(1<<i)==0)printf("*");
            else printf(".");
        }
        puts("");
    }
    return 0;
}
