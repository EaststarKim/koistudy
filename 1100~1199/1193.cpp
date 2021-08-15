#include <stdio.h>
double a[110],s;
int main(){
    int i,n,k;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%lf",a+i);
    for(i=1;i<=n;++i){
        scanf("%d",&k);
        if(a[i]<30&&k)s+=30;
        else s+=a[i];
    }
    printf("%.2lf",s/n);
    return 0;
}
