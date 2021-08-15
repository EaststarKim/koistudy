#include <stdio.h>
#define M 1000000007
int p[6]={1};
int D[1010][250],ans;
int main(){
    int i,j,k,l,n,m,t;
    scanf("%d%d",&n,&m);
    D[0][0]=1;
    for(i=1;i<=n;++i)p[i]=p[i-1]*3;
    for(i=0;i<=m;++i){
        for(j=0;j<p[n]-1;++j)if(D[i][j]){
            t=j;
            int a[3]={};
            for(k=0;k<n;++k)a[t%3]=k+1,t/=3;
            for(k=0;k<3;++k){
                for(l=0;l<3;++l)if(k!=l&&a[k]>a[l]){
                    t=j+p[a[k]-1]*(l-k);
                    D[i+1][t]=(D[i+1][t]+D[i][j])%M;
                }
            }
        }
    }
    for(i=1;i<=m;++i)ans=(ans+D[i][p[n]-1])%M;
    printf("%d",ans);
    return 0;
}
