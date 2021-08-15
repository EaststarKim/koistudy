#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int t[510],D[510][110];
int main(){
    int i,j,k,n,m,a,b,x,y,s;
    scanf("%d%d%d%d%d%d",&n,&m,&a,&b,&x,&y);
    for(i=1;i<=m;++i)scanf("%d",t+i);
    for(i=0;i<=m;++i){
        for(j=1;j<=n;++j)D[i][j]=1e6;
    }
    for(i=1;i<=n;++i)D[0][i]=abs(i-a)*y;
    for(i=1;i<=m;++i){
        for(j=1;j<=n;++j){
            for(k=1;k<=n;++k){
                s=D[i-1][j]+abs(j-k)*y;
                if(j==k&&(k==t[i]||k==t[i]+1))D[i][k]=min(D[i][k],D[i-1][j]+x);
                else if((j<=t[i]&&t[i]<k)||(k<=t[i]&&t[i]<j))D[i][k]=min(D[i][k],s-y);
                else D[i][k]=min(D[i][k],s);
            }
        }
    }
    printf("%d",D[m][b]);
    return 0;
}
