#include <stdio.h>
int a[20010],s[1010],t[1010];
int main(){
    int i,j,m,n,p;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    n/=2;
    for(i=1;i<=n;++i)++s[a[i]],++t[a[n+i]];
    for(i=n;i;--i){
        for(p=0,j=m;p>=0&&j;--j)p+=t[j+1]-s[j];
        if(p>=0)break;
        --s[a[i]],++t[a[i]],--t[a[i*2-1]],--t[a[i*2]];
    }
    printf("%d",i);
    return 0;
}
