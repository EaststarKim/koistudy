#include <stdio.h>
int main(){
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=n;i--;){
        for(j=1;j<=m;++j)printf("%d ",i*m+j);
        puts("");
    }
    return 0;
}
