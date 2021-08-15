#include <stdio.h>
int a[10],mn=1e6,mi;
char ans[1000010];
int main(){
    int i,j=9,d,n;
    scanf("%d",&d);
    for(i=1;i<10;++i){
        scanf("%d",a+i);
        if(mn>a[i])mn=a[i],mi=i;
    }
    n=d/mn;
    d-=n*mn;
    for(i=0;i<n;++i){
        ans[i]=mi+48;
        for(;j>mi;--j)if(d>=a[j]-a[mi]){
            d-=a[j]-a[mi];
            ans[i]=j+48;
            break;
        }
    }
    if(!n)puts("-1");
    puts(ans);
    return 0;
}
