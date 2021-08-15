#include <stdio.h>
int D[4][1010][1010];
int main(){
    int i,j,k,h,l,t,x,y,z;
    scanf("%d%d%d",&h,&l,&t);
    D[(h<2)*2+(l<1)][0][l+1]=1;
    for(i=0;i<t;++i){
        for(j=0;j<4;++j){
            for(k=1;k<=h+l;++k)if(D[j][i][k]){
                for(z=k-1;z<k+2;++z){
                    x=j,y=i+1;
                    if(z==1)x|=1;
                    if(z==h+l)x|=2;
                    D[x][y][z]=(D[x][y][z]+D[j][i][k])%1000000007;
                }
            }
        }
    }
    printf("%d",D[3][t][l+1]);
    return 0;
}
