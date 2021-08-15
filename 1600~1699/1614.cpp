#include <stdio.h>
int a[100010];
int main(){
    int i,n,q,l,r;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;++i)scanf("%d",a+i),a[i]+=a[i-1];
    for(;q--;){
        scanf("%d%d",&l,&r);
        printf("%d\n",a[r]-a[l-1]);
    }
    return 0;
}
