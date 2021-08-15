#include <stdio.h>
#include <string.h>
#define MOD 1000000007
int a[10][10][9];
long long D[10][100010],s;
char c[10];
int main()
{
    int i,j,l,m,n,k,t;
    scanf("%d%d",&n,&k);
    for(i=1;i<=k;++i){
        scanf("%s",c);
        t=strlen(c);
        ++a[c[0]-48][c[t-1]-48][t];
    }
    for(i=1;i<10;++i)D[i][0]=1;
    for(i=0;i<n;++i){
        for(j=1;j<10;++j)if(D[j][i]){
            for(l=1;l<10;++l){
                for(m=2;m<9;++m)if(a[j][l][m])D[l][i+m]=(D[l][i+m]+D[j][i]*a[j][l][m])%MOD;
            }
        }
    }
    for(i=1;i<10;++i)s+=D[i][n];
    printf("%d",s%MOD);
    return 0;
}
