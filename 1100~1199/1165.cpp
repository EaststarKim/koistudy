#include <stdio.h>
int a[11],D[99999]={1},mx;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
    int i,j,n,g;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i),g=gcd(a[i],g);
    if(g>1){
        puts("0");
        return 0;
    }
    for(i=0;i<90000;++i){
        if(D[i])for(j=1;j<=n;++j)D[i+a[j]]=1;
        else mx=i;
    }
    printf("%d",mx);
    return 0;
}
