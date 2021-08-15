#include <stdio.h>
#define MOD 100000007
int a[3]={2,1,1};
long long mat[3][3]={{1,1,1},{1,0,0},{0,1,0}};
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
    int i,j,k,n,m=1,t[3];
    scanf("%d",&n);
    if(n<2){
        printf("%d",a[2-n]);
        return 0;
    }
    n-=2;
    for(i=0;i<32;++i,m<<=1){
        if(n&m){
            for(j=0;j<3;++j){
                t[j]=0;
                for(k=0;k<3;++k)t[j]=(t[j]+mat[j][k]*a[k])%MOD;
            }
            for(j=0;j<3;++j)a[j]=t[j];
        }
        mul();
    }
    printf("%d",a[0]);
    return 0;
}
