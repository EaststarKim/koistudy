#include<stdio.h>   
int a,b; 
main(){   
    long long c,d,e,i,j,k,z=1000000007;   
    scanf("%d%d",&a,&b);   
    for(c=d=1,i=--a;i>b;)   
        c*=i--,c%=z,d*=a-i,d%=z;   
    for(e=1,j=536870912,k=z-2;j>0;j/=2)   
    {   
        e*=e;   
        e%=z;   
        if(k>=j){k-=j;e*=d;e%=z;}   
    }   
    if(a<b)c=0;   
    printf("%lld",(c*e*2)%z);   
}  
