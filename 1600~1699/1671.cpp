#include <stdio.h>
int a[110],n;
void f(int p){
    if(p==n){
        printf("%d ",a[p]);
        return;
    }
    if(a[p]>a[p+1])f(p+1);
    printf("%d ",a[p]);
    if(a[p]<a[p+1])f(p+1);
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    f(1);
    return 0;
}
