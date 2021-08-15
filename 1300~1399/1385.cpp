#include <stdio.h>
char a[60][60];
int main(){
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)a[i][j]='.';
    }
    for(i=j=1;;){
        for(j=1;j<=m;++j)a[i][j]='#';
        if(i<n)a[++i][m]='#';
        else break;
        if(i<n)a[++i][m]='#';
        else break;
        for(j=m;j;--j)a[i][j]='#';
        if(i<n)a[++i][1]='#';
        else break;
        if(i<n)a[++i][1]='#';
        else break;
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)printf("%c",a[i][j]);
        puts("");
    }
    return 0;
}
