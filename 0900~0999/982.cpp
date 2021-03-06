#include <stdio.h>
#define MOD 100000007
long long mat[2][2]={{1,1},{1,0}},n,m=1;
void mul(){
    int i,j,t[2][2];
    for(i=0;i<2;++i){
        for(j=0;j<2;++j)t[i][j]=(mat[i][0]*mat[0][j]+mat[i][1]*mat[1][j])%MOD;
    }
    for(i=0;i<2;++i){
        for(j=0;j<2;++j)mat[i][j]=t[i][j];
    }
}
int main()
{
    int i,j,a[2]={1,1},t[2];
    scanf("%lld",&n);
    --n;
    for(i=0;i<34;++i,m<<=1){
        if(n&m){
            for(j=0;j<2;++j){
                t[j]=(mat[j][0]*a[0]+mat[j][1]*a[1])%MOD;
            }
            a[0]=t[0];
            a[1]=t[1];
        }
        mul();
    }
    printf("%d",a[0]);
    return 0;
}
