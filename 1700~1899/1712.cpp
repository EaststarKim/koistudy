#include <stdio.h>
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(j=n;j;--j){
        for(i=0;i<n;++i)printf("%d ",i*n+j);
        puts("");
    }
    return 0;
}
