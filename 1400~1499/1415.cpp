#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char a[1010][1010];
int D[1010][1010][2][2][2][2][2],n,m;
int f(int r,int c,int u,int l,int p,int pd,int pr){
    if(r<1||r>n||c<1||c>m)return 1e5;
    int &ans=D[r][c][u][l][p][pd][pr],sum;
    if(ans>=0)return ans;
    if(r==n&&c==m)return ans=(!p)*a[n][m];
    int s[4]={(!u)*a[r-1][c],(!l)*a[r][c-1],a[r+1][c],a[r][c+1]};
    sum=(!p)*a[r][c]+s[0]+s[1]+s[2]+s[3];
    ans=1e5;
    ans=min(ans,sum-max(s[0],s[1])+min(f(r+1,c,1,pd,1,0,1),f(r,c+1,pr,1,1,1,0)));
    ans=min(ans,sum-s[2]+min(f(r+1,c,1,pd,0,0,1),f(r,c+1,pr,1,1,0,0)));
    ans=min(ans,sum-s[3]+min(f(r+1,c,1,pd,1,0,0),f(r,c+1,pr,1,0,1,0)));
    return ans;
}
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        scanf("%s",a[i]+1);
        for(j=1;j<=m;++j)a[i][j]=(a[i][j]=='.'?0:a[i][j]-48);
    }
    memset(D,-1,sizeof D);
    printf("%d",f(1,1,0,0,0,0,0));
    return 0;
}
