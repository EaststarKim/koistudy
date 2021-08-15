#include <stdio.h>
int D[35010];
int main(){
    int i,c,b,k;
    scanf("%d%d",&c,&b);
    D[0]=1;
    for(;b--;){
        scanf("%d",&k);
        for(i=c;i>=k;--i)if(D[i-k])D[i]=1;
    }
    for(i=c;i;--i)if(D[i])break;
    printf("%d",i);
    return 0;
}
