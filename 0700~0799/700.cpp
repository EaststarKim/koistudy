#include <stdio.h>
#define M 1000000000
long long mat[2][2]={4,4,1,0},n;
void mul(){
    int i,j,t[2][2];
    for(i=0;i<2;++i)for(j=0;j<2;++j)t[i][j]=(mat[i][0]*mat[0][j]+mat[i][1]*mat[1][j])%M;
    for(i=0;i<2;++i)for(j=0;j<2;++j)mat[i][j]=t[i][j];
}
int main(){
    int i,j,t,a[2]={8,2},b[2];
    scanf("%lld",&n);
    n-=3;
    if(n<0)a[0]=n+2;
    for(t=1;t<=n;t*=2,mul())if(n&t){
        for(j=0;j<2;++j)b[j]=(mat[j][0]*a[0]+mat[j][1]*a[1])%M;
        a[0]=b[0],a[1]=b[1];
    }
    printf("%d",a[0]);
    return 0;
}
