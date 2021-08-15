#include <stdio.h>
int a[1000010],b[1000010],q[1000010],ans[1000010],r;
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=n;++i)scanf("%d",b+i);
    for(i=n;i;--i){
        while(r&&a[q[r]]<=a[i])--r;
        q[++r]=i;
        if(r>b[i])ans[i]=a[q[r-b[i]]];
        else ans[i]=-1;
    }
    for(i=1;i<=n;++i)printf("%d ",ans[i]);
    return 0;
}
