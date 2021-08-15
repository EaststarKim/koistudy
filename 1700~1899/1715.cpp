#include <stdio.h>
int main(){
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=n;i;--i){
        for(j=m;j--;)printf("%d ",i+j*n);
        puts("");
    }
    return 0;
}
