#include <stdio.h>
int a[60];
int main(){
    int i,n,s;
    scanf("%d%d",&n,&s);
    if((!s&&n>1)||s>n*9){
        puts("-1");
        return 0;
    }
    for(i=1;i<=n;++i){
        if(s>8)printf("9"),s-=9;
        else printf("%d",s),s=0;
    }
    return 0;
}
