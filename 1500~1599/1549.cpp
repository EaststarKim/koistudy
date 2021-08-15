#include <stdio.h>
int main(){
    int i,j,n,m;
    scanf("%d%d",&m,&n);
    printf("+");
    for(i=2;i<m;++i)printf("-");
    puts("+");
    for(i=2;i<n;++i){
        printf("|");
        for(j=2;j<m;++j)printf(" ");
        puts("|");
    }
    printf("+");
    for(i=2;i<m;++i)printf("-");
    puts("+");
    return 0;
}
