#include <stdio.h>
int main(){
    int i,a,t;
    scanf("%d",&a);
    for(i=1;;++i){
        ++a;
        t=a>0?a:-a;
        while(t){
            if(t%10==8){
                printf("%d",i);
                return 0;
            }
            t/=10;
        }
    }
}
