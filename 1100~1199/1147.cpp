#include <stdio.h>
#include <string.h>
int a[210][3],chk[110],s[210];
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)for(j=0;j<3;++j)scanf("%d",a[i]+j);
    for(i=0;i<3;++i){
        for(j=1;j<=n;++j)++chk[a[j][i]];
        for(j=1;j<=n;++j)if(chk[a[j][i]]<2)s[j]+=a[j][i];
        memset(chk,0,sizeof chk);
    }
    for(i=1;i<=n;++i)printf("%d\n",s[i]);
    return 0;
}
