#include <stdio.h>
int main(){
    int i,w,n;
    long long s=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",&w),s+=w;
    printf("%d",s<0?-1:s>0);
    return 0;
}
