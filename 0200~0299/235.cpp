#include <stdio.h>
int a[110],chk[110];
char c[110][7];
int main(){
    int i,j,n,mx,mi;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%s",c[i]),a[i]=-c[i][3]+c[i][4]*100+c[i][5]*10+c[i][6]-5259;
    for(i=1;i<=n;++i){
        mx=0;
        for(j=1;j<=n;++j)if(!chk[j]&&mx<a[j])mx=a[j],mi=j;
        chk[mi]=1;
        for(j=0;j<4;++j)printf("%c",c[mi][j]);
        printf("%03d\n",a[mi]+c[mi][3]-69);
        for(j=1;j<mi;++j)++a[j];
    }
    return 0;
}

