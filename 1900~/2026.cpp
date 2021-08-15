#include <stdio.h>
int main(){
    int i,n,c,s=0,mx=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&c);
        s+=c;
        if(mx<c)mx=c;
    }
    printf("%d",s-mx);
    return 0;
}
