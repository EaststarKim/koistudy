#include <stdio.h>
int a[5010],b[5010];
int main(){
    int i,j,k,n,m,t;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i)a[i]=i+1;
    for(i=n;i;--i){
        j=(m-1)%i;
        printf("%d ",a[j]);
        t=0;
        for(k=(j+1)%i;k!=j;k=(k+1)%i)b[t++]=a[k];
        for(k=0;k<t;++k)a[k]=b[k];
    }
    return 0;
}
