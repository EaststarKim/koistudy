#include <stdio.h>
int gcd(int x,int y){
    if(x%y==0)return y;
    return gcd(y,x%y);
}
int main()
{
    int i,n,g,k;
    scanf("%d%d",&n,&g);
    for(i=1;i<n;++i){
        scanf("%d",&k);
        g=gcd(g,k);
    }
    printf("%d",g*n);
    return 0;
}
