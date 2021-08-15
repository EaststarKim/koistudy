#include <stdio.h>
#include <string.h>
int D[1010][1010];
char a[1010],b[1010];
int main()
{
    int i,j,n,m;
    scanf("%s%s",a,b);
    n=strlen(a);
    m=strlen(b);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            if(a[i-1]==b[j-1])D[i][j]=D[i-1][j-1]+1;
            else D[i][j]=D[i][j-1]>D[i-1][j]?D[i][j-1]:D[i-1][j];
        }
    }
    printf("%d",D[n][m]);
    return 0;
}
