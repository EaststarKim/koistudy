#include <stdio.h>
#define MOD 1000000
int a[3]={22,7,2};
long long mat[3][3]={{3,1,-1},{1,0,0},{0,1,0}};
void mul(){
    int i,j,k,t[3][3];
    for(i=0;i<3;++i){
        for(j=0;j<3;++j){
            t[i][j]=0;
            for(k=0;k<3;++k)t[i][j]=(t[i][j]+mat[i][k]*mat[k][j])%MOD;
        }
    }
    for(i=0;i<3;++i){
        for(j=0;j<3;++j)mat[i][j]=t[i][j];
    }
}
int main()
{
    int i,j,k,t[3];
    long long n,m=1;
    scanf("%lld",&n);
    if(n<4){
        printf("%d",a[3-n]);
        return 0;
    }
    n-=3;
    for(i=0;i<37;++i,m<<=1){
        if(n&m){
            for(j=0;j<3;++j){
                t[j]=0;
                for(k=0;k<3;++k)t[j]=(t[j]+mat[j][k]*a[k])%MOD;
            }
            for(j=0;j<3;++j)a[j]=t[j];
        }
        mul();
    }
    if(a[0]<0)a[0]+=MOD;
    printf("%d",a[0]);
    return 0;
}
