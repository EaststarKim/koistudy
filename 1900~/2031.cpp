#include <stdio.h>
#include <algorithm>
using namespace std;
char a[100010];
int D[100010][16][16],ans;
int f(int x,int y,int z){
    if(!x){
        if(!y)return 1;
        return 2-(y==z);
    }
    if(x==y&&y==z)return 1;
    return 3-(x==y)-(y==z)-(z==x);
}
int main(){
    int i,j,k,n;
    scanf("%d\n%s",&n,a+1);
    D[0][0][0]=1;
    for(i=1;i<=n;++i){
        if(a[i]=='M')a[i]=1;
        else if(a[i]=='F')a[i]=2;
        else a[i]=3;
        for(j=0;j<16;++j){
            for(k=0;k<16;++k)if(D[i-1][j][k]){
                D[i][j/4+a[i]*4][k]=max(D[i][j/4+a[i]*4][k],D[i-1][j][k]+f(j&3,j/4,a[i]));
                D[i][j][k/4+a[i]*4]=max(D[i][j][k/4+a[i]*4],D[i-1][j][k]+f(k&3,k/4,a[i]));
            }
        }
    }
    for(i=0;i<16;++i){
        for(j=0;j<16;++j)ans=max(ans,D[n][i][j]);
    }
    printf("%d",ans-1);
    return 0;
}
