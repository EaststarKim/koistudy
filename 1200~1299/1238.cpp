#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[1010][1010],D[1010][1010][4],n;
int f(int r,int c,int s){
    if(r==n)return !s?0:(s==3?1:1e9);
    int &ans=D[r][c][s];
    if(ans>=0)return ans;
    if(s&2)return ans=min(f(r+1,c,!(s&1)*2+!a[r+1][c]),f(r+1,c+1,!(s&1)*2+!a[r+1][c+1]))+1;
    return ans=min(f(r+1,c,s*2+a[r+1][c]),f(r+1,c+1,s*2+a[r+1][c+1]));
}
int main(){
    int i,j,ans=1e9;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        for(j=1;j<=i;++j)scanf("%d",a[i]+j);
    }
    memset(D,-1,sizeof D);
    for(i=1;i<3;++i)ans=min(ans,min(f(2,i,a[1][1]*2+a[2][i]),f(2,i,!a[1][1]*2+!a[2][i])+1));
    if(ans>=1e9)ans=-1;
    printf("%d",ans);
    return 0;
}
