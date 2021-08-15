#include <stdio.h>
int a[1010][1010],s[110];
int main(){
    int i,j,k,n,r,c,w,h;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d%d%d%d",&r,&c,&w,&h);
        for(j=0;j<w;++j)for(k=0;k<h;++k)a[r+j][c+k]=i;
    }
    for(i=0;i<1001;++i)for(j=0;j<1001;++j)++s[a[i][j]];
    for(i=1;i<=n;++i)printf("%d\n",s[i]);
    return 0;
}
