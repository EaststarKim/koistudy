#include <stdio.h>
int g(int x,int y){return y?g(y,x%y):x;}
int main(){
    int i,n,m,k,t=360;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%d",&k),t=g(t,k);
    for(;m--;){
        scanf("%d",&k);
        puts(k%t?"NO":"YES");
    }
    return 0;
}
