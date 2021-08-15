#include <stdio.h>
int a[110],b[2010],c[2010],q[2010],chk[110],f,r,ans;
int main(){
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=m;++i)scanf("%d",b+i);
    for(i=1;i<=m*2;++i){
        scanf("%d",&k);
        if(k<0)chk[c[-k]]=0;
        else q[++r]=k;
        if(f<r){
            for(j=1;j<=n;++j)if(!chk[j]){
                ans+=a[j]*b[q[++f]];
                chk[j]=1;
                c[q[f]]=j;
                break;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
