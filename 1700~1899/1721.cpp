#include <stdio.h>
int main(){
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=n;i;--i){
        for(j=1;j<=m;++j)printf("%d ",i*m+(i&1?1-j:j-m));
        puts("");
    }
    return 0;
}
