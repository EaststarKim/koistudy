#include <stdio.h>
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)printf("%d ",j*n+(j&1?i-n:1-i));
        puts("");
    }
    return 0;
}
