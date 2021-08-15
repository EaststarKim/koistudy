#include <stdio.h>
#include <algorithm>
using namespace std;
char a[110][110];
int D[210][110][110],chk[210][110][110];
int main()
{
    int i,j,k,w,h,s,t;
    scanf("%d%d",&w,&h);
    for(i=1;i<=h;++i)scanf("%s",a[i]+1);
    if(a[1][1]=='*')D[2][1][1]=1;
    chk[2][1][1]=1;
    for(i=3;i<=w+h;++i){
        for(j=1;j<i;++j)if(j<=h&&i-j<=w&&a[j][i-j]!='#'){
            for(k=1;k<i;++k)if(k<=h&&i-k<=w&&a[k][i-k]!='#'){
                s=0,t=-1;
                if(a[j][i-j]=='*')++s;
                if(a[k][i-k]=='*')++s;
                if(j==k&&s>1)s=1;
                if(chk[i-1][j][k])t=max(t,D[i-1][j][k]);
                if(chk[i-1][j][k-1])t=max(t,D[i-1][j][k-1]);
                if(chk[i-1][j-1][k])t=max(t,D[i-1][j-1][k]);
                if(chk[i-1][j-1][k-1])t=max(t,D[i-1][j-1][k-1]);
                if(t>=0){
                    D[i][j][k]=t+s;
                    chk[i][j][k]=1;
                }
            }
        }
    }
    printf("%d",D[w+h][h][h]);
    return 0;
}
