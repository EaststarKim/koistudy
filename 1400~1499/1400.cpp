#include <stdio.h>
int main(){
    int i,n,s;
    scanf("%d",&n);
    if(n<4)printf("%d",n);
    for(i=4,s=3;i<=n;++i){
        if(s==i-1)s-=2;
        else if(s==1)s=i;
        else --s;
    }
    printf("%d",s);
    return 0;
}
