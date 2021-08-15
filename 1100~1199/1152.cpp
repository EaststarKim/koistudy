#include <stdio.h>
#include <stdlib.h>
int a[3],b[3];
int main(){
    int i,j,n,k,s=1,t=1,u=1;
    scanf("%d",&n);
    for(i=0;i<3;++i)scanf("%d",a+i);
    for(i=0;i<3;++i)scanf("%d",b+i);
    for(i=0;i<3;++i){
        for(j=1,k=0;j<=n;++j)if(abs(j-a[i])%(n-2)<3)++k;
        s*=k;
    }
    for(i=0;i<3;++i){
        for(j=1,k=0;j<=n;++j)if(abs(j-b[i])%(n-2)<3)++k;
        t*=k;
    }
    for(i=0;i<3;++i){
        for(j=1,k=0;j<=n;++j)if(abs(j-a[i])%(n-2)<3&&abs(j-b[i])%(n-2)<3)++k;
        u*=k;
    }
    printf("%d",s+t-u);
    return 0;
}
