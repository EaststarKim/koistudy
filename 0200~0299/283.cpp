#include <stdio.h>
int a[110][110],b[110][110],chk[110][110];
int main(){
    int i,j,k,n,x,y,z,updated=1;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d%d%d",&x,&y,&z);
        a[x][y]=b[x][y]=z;
    }
    for(;updated;){
        updated=0;
        for(i=1;i<101;++i){
            for(j=1;j<101;++j)if(b[i][j]>50&&!chk[i][j]){
                chk[i][j]=1;
                for(k=1;k<101;++k)if(a[j][k])b[i][k]+=a[j][k],updated=1;
            }
        }
    }
    for(i=1;i<101;++i){
        for(j=1;j<101;++j)if(i!=j&&b[i][j]>50)printf("%d %d\n",i,j);
    }
    return 0;
}
