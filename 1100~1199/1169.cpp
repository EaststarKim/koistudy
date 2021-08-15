#include <stdio.h>
int a[10],flag;
int main(){
    int i,k,n,m;
    scanf("%d%d",&k,&n);
    for(i=1;i<=n;++i)scanf("%d",&m),++a[m];
    for(i=1;i<=k;++i)if(!a[i])printf("%d ",i),flag=1;
    if(!flag)printf("good");
    return 0;
}
