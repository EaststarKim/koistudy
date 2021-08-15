#include <stdio.h>
int main(){
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        for(j=m;j;--j)printf("%d ",j*n+(j&1?1-i:i-n));
        puts("");
    }
    return 0;
}
