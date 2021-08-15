#include <stdio.h>
int b[3],D[531][531];
int main()
{
    int i,j,k,k1,k2;
    scanf("%d%d%d",b,b+1,b+2);
    for(i=0;i<501;++i){
        for(j=0;j<501;++j){
            for(k=0;k<3;++k){
                if(!D[i][j]|!D[i+b[k]][j])D[i+b[k]][j]=!D[i][j];
                if(!D[i][j]|!D[i][j+b[k]])D[i][j+b[k]]=!D[i][j];
            }
        }
    }
    for(i=1;i<6;++i){
        scanf("%d%d",&k1,&k2);
        if(D[k1][k2])puts("A");
        else puts("B");
    }
    return 0;
}
