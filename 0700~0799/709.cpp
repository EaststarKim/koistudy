#include <stdio.h>
#include "lib.h"
int main(){
    int i=100,j=1,k,t;
    scanf("%d",&k);
    for(;;){
        t=function(i,j);
        if(k==t){
            printf("%d %d",i,j);
            return 0;
        }
        if(k>t)++j;
        else --i;
    }
}
