#include <stdio.h>
int main(){
    int i,n,s,t;
    scanf("%d",&n);
    for(i=n+n%2;;i+=2){
        for(s=i;s>0;s-=s%2){
            if(s%10)s/=10;
            else{
                t=s=s/10-1;
                if(s%2){
                    for(;t%2;t/=10);
                    s-=t;
                }
            }
        }
        if(!s){
            printf("%d",i);
            return 0;
        }
    }
}
