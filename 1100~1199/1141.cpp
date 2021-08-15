#include <stdio.h>
int main(){
    int i,n,m,a,b,s;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    s=n*a;
    for(i=1;n;++i){
        n=n-m>0?n-m:0;
        if(s>n*a+i*b)s=n*a+i*b;
    }
    printf("%d",s);
    return 0;
}
