#include <stdio.h>
int a[51],b[51],c[51],m1=1e4,m2=1e4;
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=2;i<=n;++i)scanf("%d",a+i),a[i]+=a[i-1];
    for(i=1;i<n;++i)scanf("%d",b+i);
    for(;--i;)b[i]+=b[i+1];
    for(i=1;i<=n;++i)scanf("%d",c+i);
    for(i=1;i<=n;++i){
        int s=a[i]+b[i]+c[i];
        if(m1>s)m2=m1,m1=s;
        else if(m2>s)m2=s;
    }
    printf("%d",m1+m2);
    return 0;
}
