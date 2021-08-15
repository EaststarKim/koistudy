#include <stdio.h>
int n,m,k,ans;
void f(int i,int p,int s){
    if(s>k)return;
    if(i>n*n){
        ++ans;
        return;
    }
    for(int j=p+1;j<=m-n*n+i;++j)f(i+1,j,s+j);
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    f(1,0,0);
    printf("%d",ans);
    return 0;
}
