#include <stdio.h>
#include <string.h>
int max(int a,int b){return a>b?a:b;}
int D[1010][1010],s[5][5]={{5,-3,-1,-1,-2},{-3,5,-3,-4,-2},{-1,-3,5,-2,-3},{-1,-4,-2,5,-1},{-2,-2,-3,-1}};
char a[1010],b[1010];
int main()
{
    int i,j,n,m;
    scanf("%s%s",a+1,b+1);
    n=strlen(a+1);
    m=strlen(b+1);
    for(i=1;i<=n;++i)D[i][0]=D[i-1][0]+s[a[i]-65][4];
    for(i=1;i<=m;++i)D[0][i]=D[0][i-1]+s[4][b[i]-65];
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)D[i][j]=max(D[i-1][j-1]+s[a[i]-65][b[j]-65],max(D[i-1][j]+s[a[i]-65][4],D[i][j-1]+s[4][b[j]-65]));
    }
    printf("%d",D[n][m]);
    return 0;
}
