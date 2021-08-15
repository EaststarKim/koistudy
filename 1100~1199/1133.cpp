#include <stdio.h>
#include <algorithm>
using namespace std;
int D[1010][1010],n,t;
int f(int a){
    int i;
    if(a==n)return 0;
    if(D[a][n-a])return D[a][n-a];
    D[a][n-a]=1e9;
    for(i=0;i<6;++i)if(a>=i&&n-a>=5-i)D[a][n-a]=min(D[a][n-a],f(a+5-i*2)+1);
    return D[a][n-a];
}
int main(){
    int i,k;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",&k),t+=k;
    printf("%d",f(t)==1e9?-1:D[t][n-t]);
    return 0;
}
