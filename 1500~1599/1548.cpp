#include <stdio.h>
int a[2010],b[110];
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i),++b[a[i]];
    for(i=100;--i;)b[i]+=b[i+1];
    for(i=1;i<=n;++i)printf("%d\n",b[a[i]+1]+1);
    return 0;
}
