#include <stdio.h>
int a[100010],t,s;
int main(){
    int i,n,k;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&k);
        if(!k)--t;
        else a[++t]=k;
    }
    for(i=1;i<=t;++i)s+=a[i];
    printf("%d",s);
    return 0;
}
