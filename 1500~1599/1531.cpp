#include <stdio.h>
#include <algorithm>
using namespace std;
int a[5][30];
int chk[5][30],n,ans;
void f(int r,int c,int s){
    if(chk[r][c]){
        f(r+1,c,s);
        return;
    }
    if(r>3){
        if(c==n)ans=max(ans,s);
        else f(1,c+1,s);
        return;
    }
    if(r<3&&!chk[r+1][c]){
        chk[r][c]=chk[r+1][c]=1;
        f(r+2,c,s+min(a[r][c],a[r+1][c]));
        chk[r][c]=chk[r+1][c]=0;
    }
    if(c<n&&!chk[r][c+1]){
        chk[r][c]=chk[r][c+1]=1;
        f(r+1,c,s+min(a[r][c],a[r][c+1]));
        chk[r][c]=chk[r][c+1]=0;
    }
}
int main(){
    int i,j;
    scanf("%d",&n);
    if(n%2){
        puts("0");
        return 0;
    }
    for(i=1;i<4;++i){
        for(j=1;j<=n;++j)scanf("%d",a[i]+j);
    }
    f(1,1,0);
    printf("%d",ans);
    return 0;
}
