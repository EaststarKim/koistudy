#include <stdio.h>
int a[1010],s[1010],mx,mi;
int main(){
    int i,j,n,m,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=m;++i){
        scanf("%d",&b);
        for(j=1;j<=n&&a[j]>b;++j);
        ++s[j];
    }
    for(i=1;i<=n;++i)if(mx<s[i])mx=s[i],mi=i;
    printf("%d",mi);
    return 0;
}
