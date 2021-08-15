#include <stdio.h>
int chk[2010][2010],cnt;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
    int i,j,d1,d2;
    scanf("%d%d",&d1,&d2);
    for(i=d1;i<=d2;++i){
        for(j=0;j<i;++j)if(!chk[j/gcd(i,j)][i/gcd(i,j)])++cnt,chk[j/gcd(i,j)][i/gcd(i,j)]=1;
    }
    printf("%d",cnt);
    return 0;
}
