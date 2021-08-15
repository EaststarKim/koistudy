#include <stdio.h>
#define M 1000000007
int main(){
    int i,n,k,m=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",&k),m=m<k?k:m;
    for(;--n;)m=m*2%M;
    printf("%d",m);
    return 0;
}
