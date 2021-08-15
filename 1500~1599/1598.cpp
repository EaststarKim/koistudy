#include <stdio.h>
int main(){
    int i,n,cnt=0,sum=0;
    scanf("%d",&n);
    for(i=1;i*i<n;++i)if(n%i==0)cnt+=2,sum+=i+n/i;
    if(i*i==n)++cnt,sum+=i;
    printf("%d\n%d",cnt-1,sum-n);
    return 0;
}
