#include <stdio.h>
int a[9][9],n,ans;
void back(int r,int c){
    int i,j;
    if(c>n){
        back(r+1,1);
        return;
    }
    if(r>n){
        for(i=1;i<=n;++i){
            for(j=1;j<=n;++j)if(!a[i][j])return;
        }
        ++ans;
        return;
    }
    if(a[r][c]){
        back(r,c+1);
        return;
    }
    if(c<n&&!a[r][c+1]){
        a[r][c]=a[r][c+1]=1;
        back(r,c+2);
        a[r][c]=a[r][c+1]=0;
    }
    if(r<n&&!a[r+1][c]){
        a[r][c]=a[r+1][c]=1;
        back(r,c+1);
        a[r][c]=a[r+1][c]=0;
    }
}
int main(){
    scanf("%d",&n);
    if(n%2)ans=-1;
    else back(1,1);
    printf("%d",ans);
    return 0;
}
