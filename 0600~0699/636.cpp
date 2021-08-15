#include <stdio.h>   
  
  
long long n;   
long long e2[100],e3[100],N2,N3;   
int count;   
  
void f(long long N, int two, int three){   
    if(N==0){   
        count++;   
        return ;   
    }   
  
    while(N%2==0) N/=2, two--;   
    while(N%3==0) N/=3, three--;   
  
    if(three>0) return ;   
  
    int i,j;   
    for(i=two;i>=0;i--) for(j=0;j<=N3;j++){   
        if(N-e2[i]*e3[j]>=0) f(N-e2[i]*e3[j],i-1,j+1);   
        else break;   
    }   
}   
  
int main(){   
    scanf("%lld",&n);   
  
    while(n%2==0) n/=2;   
    while(n%3==0) n/=3;   
  
    int i;   
    e2[0]=e3[0]=1;   
    for(i=1;e2[i-1]<=n;i++) e2[i]=e2[i-1]*2; N2=i-1;   
    for(i=1;e3[i-1]<=n;i++) e3[i]=e3[i-1]*3; N3=i-1;   
  
    f(n,N2,0);   
    if(n==1) count=0;   
    printf("%d",count);   
  
} 