#include <stdio.h>
int main(){
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=n;i;--i){
        for(j=1;j<=m;++j)printf("%d ",i*m+(i&1?j-m:1-j));
        puts("");
    }
    return 0;
}
