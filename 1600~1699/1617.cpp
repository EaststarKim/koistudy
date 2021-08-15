#include <stdio.h>
int a[1<<19];
int main(){
    int i,n,t;
    scanf("%d",&n);
    for(t=1;t<n;t*=2);
    for(i=0;i<n;++i)scanf("%d",a+i+t);
    for(i=t;--i;)a[i]=a[i*2]+a[i*2+1];
    for(i=1;i<t+n;++i)printf("%d ",a[i]);
    return 0;
}
