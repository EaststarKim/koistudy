#include<stdio.h>   
int main(){
    long long int a,b,c,d,i;   
    scanf("%lld%lld%lld",&a,&b,&c);   
    d=1;   
    for(i=1;i<a;i++){   
        d*=(2*i+1);   
        d=d%c;   
    }   
    printf("%lld",d);   
}  
