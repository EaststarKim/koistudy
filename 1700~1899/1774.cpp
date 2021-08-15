#include <stdio.h>
int a[100010],chk[100010],ans;
int main(){
    int i,n,m,x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)a[i]=1;
    chk[1]=1;
    for(;m--;){
        scanf("%d%d",&x,&y);
        --a[x],++a[y];
        if(chk[x])chk[y]=1;
        if(!a[x])chk[x]=0;
    }
    for(i=1;i<=n;++i)ans+=chk[i];
    printf("%d",ans);
    return 0;
}
