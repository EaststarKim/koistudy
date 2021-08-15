#include <stdio.h>
int a[10000010],s;
int f(int k){
    if(!a[k])return a[k]=k;
    return a[k]=f(a[k]+1);
}
int main(){
    int i,n,m,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i){
        scanf("%d",&k);
        s=(s+f(k)-k)%20120702;
    }
    printf("%d",s);
    return 0;
}
