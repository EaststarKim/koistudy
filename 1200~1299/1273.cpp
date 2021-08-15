#include <stdio.h>
#include <math.h>
int main(){
    int i,n,m,cnt=0;
    scanf("%d",&n);
    m=sqrt(n);
    for(i=2;i<=m;++i)if(n%i==0)++cnt;
    cnt*=2;
    if(m*m==n)--cnt;
    printf("%d",cnt+1);
    return 0;
}
