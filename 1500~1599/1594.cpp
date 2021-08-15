#include <stdio.h>
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
    int i,j,n,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        for(j=0;j<=i;++j)ans+=(gcd(i,j)==1);
    }
    printf("%d",ans);
    return 0;
}
