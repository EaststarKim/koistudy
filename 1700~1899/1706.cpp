#include <stdio.h>
int a[200];
int main(){
    int i,j,n,l;
    scanf("%d",&n);
    a[1]=l=1;
    for(i=1;i<=n;++i){
        for(j=1;j<=l;++j)a[j]*=i;
        for(j=1;j<=l;++j)a[j+1]+=a[j]/10,a[j]%=10;
        for(;a[l+1];++l)a[l+2]+=a[l+1]/10,a[l+1]%=10;
    }
    printf("%d",l);
    return 0;
}
