#include <stdio.h>
#include <algorithm>
using namespace std;
int D[500010][2],mx[500010][2];
vector<int> e[500010];
void update(int n,int v){
    if(mx[n][0]<v)mx[n][1]=mx[n][0],mx[n][0]=v;
    else if(mx[n][1]<v)mx[n][1]=v;
}
void dp(int n,int p){
    for(auto nx:e[n]){
        if(nx==p)continue;
        dp(nx,n);
        update(n,D[nx][1]+1-D[nx][0]);
        D[n][1]+=D[nx][0];
    }
    D[n][1]+=mx[n][0];
    D[n][0]=D[n][1]+mx[n][1];
}
int main(){
    int i,n,x,y;
    scanf("%d",&n);
    for(i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dp(1,0);
    printf("%d",n-D[1][0]-1);
    return 0;
}
