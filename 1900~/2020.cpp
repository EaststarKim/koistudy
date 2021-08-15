#include <stdio.h>
int main(){
    int n,k,x=0,s=0,mn=1e9;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&k);
        x^=k,s+=k;
        if(mn>k)mn=k;
    }
    printf("%d",x?0:s-mn);
    return 0;
}
