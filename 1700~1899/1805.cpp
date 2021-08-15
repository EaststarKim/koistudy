#include <stdio.h>
int a[100010],t[100010];
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(t[1]=0;t[1]<=a[1];++t[1]){
        for(i=1;i<n;++i)t[i+1]=a[i]-t[i]-t[i-1];
        if(t[n-1]+t[n]!=a[n])continue;
        for(i=1;i<=n;++i)if(t[i]<0||t[i]>100)break;
        if(i>n){
            for(i=1;i<=n;++i)printf("%d ",t[i]);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
