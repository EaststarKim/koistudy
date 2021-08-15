#include <stdio.h>
int c[32][32];
int main(){
    int i,j,n,m;
    long long k;
    scanf("%d%d%lld",&n,&m,&k);
    for(i=0;i<n;++i){
        c[i][0]=c[i][i]=1;
        for(j=1;j<=i/2;++j)c[i][j]=c[i][i-j]=c[i-1][j]+c[i-1][j-1];
    }
    for(i=0;i<n;++i){
        for(j=1;j<=m;++j)c[i][j]+=c[i][j-1];
    }
    --k;
    while(n--){
        if(k>=c[n][m]){
            printf("1");
            k-=c[n][m--];
        }
        else printf("0");
    }
    return 0;
}
