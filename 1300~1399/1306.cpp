#include <stdio.h>
int a[100010],cnt;
int main(){
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)scanf("%d",a+i);
    for(i=0;i<n;++i)if(i%7<5){
        for(j=1;j<=m&&i%a[j];++j);
        if(j<=m)++cnt;
    }
    printf("%d",cnt);
    return 0;
}
