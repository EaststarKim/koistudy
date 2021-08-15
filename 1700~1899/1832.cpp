#include <stdio.h>
char a[110][110];
int main(){
    int i,j,n,m,d,t,ans=0;
    scanf("%d%d%d",&n,&m,&d);
    for(i=1;i<=n;++i){
        scanf("%s",a[i]+1);
        for(j=1,t=0;j<=m;++j){
            if(a[i][j]=='#')ans+=t<d?0:t-d+1,t=0;
            else ++t;
        }
        ans+=t<d?0:t-d+1;
    }
    for(j=1;j<=m;++j){
        for(i=1,t=0;i<=n;++i){
            if(a[i][j]=='#')ans+=t<d?0:t-d+1,t=0;
            else ++t;
        }
        ans+=t<d?0:t-d+1;
    }
    printf("%d",ans);
    return 0;
}
