#include <stdio.h>
#include <algorithm>
using namespace std;
int D[110][210],s[60],e[60],ans;
int f(int x,int y){
    if(x>100&&y>100)return D[x-100][y-100];
    return D[x][y];
}
int main(){
    int i,j,k,n,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d%d",s+i,e+i);
        if(s[i]>e[i])swap(s[i],e[i]);
    }
    for(i=1;i<=100;++i){
        for(j=1;j<100;++j){
            x=j,y=j+i;
            for(k=x;k<y;++k)D[x][y]=max(D[x][y],D[x][k]+f(k+1,y));
            for(k=1;k<=n;++k){
                if(x==s[k]&&y==e[k])D[x][y]=max(D[x][y],D[x+1][y-1]+1);
                if(x==e[k]&&y==s[k]+100)D[x][y]=max(D[x][y],D[x+1][y-1]+1);
            }
        }
    }
    for(i=1;i<=100;++i){
        for(j=i;j<=100;++j)ans=max(ans,D[i][j]+D[j+1][i+99]);
    }
    printf("%d",ans);
    return 0;
}
