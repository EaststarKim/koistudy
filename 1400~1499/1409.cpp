#include <stdio.h>
int main(){
    int i,k,mn=100,s=0;
    for(i=1;i<5;++i){
        scanf("%d",&k);
        s+=k;
        if(mn>k)mn=k;
    }
    scanf("%d%d",&i,&k);
    printf("%d",s-mn+(i>k?i:k));
    return 0;
}
