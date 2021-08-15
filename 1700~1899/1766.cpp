#include <stdio.h>
int a[1010],mn=2e9;
void f(int n,int h){
    if(!n){
        if(mn>h)mn=h;
        return;
    }
    if(a[n]<=h){
    	if(n)f(n-1,h-a[n]);
    	if(n>1)f(n-2,h-a[n-1]);
    }
    else f(n-1,h);
}
int main(){
    int i,n,h;
    scanf("%d%d",&n,&h);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    f(n,h);
    printf("%d",h-mn);
    return 0;
}
