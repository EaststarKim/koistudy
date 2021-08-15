#include <stdio.h>
long long D[32][10],ans;
int loc[10]={10,0,1,2,3,4,5,6,7,8};
int a[4][3]={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
int x[]={-1,0,1,0,0},y[]={0,1,0,-1,0};
int main(){
    int i,j,k,n,r,c,nr,nc;
    scanf("%d",&n);
    for(i=0;i<10;++i)D[1][i]=1;
    for(i=1;i<n;++i){
        for(j=0;j<10;++j)if(D[i][j]){
            r=loc[j]/3,c=loc[j]%3;
            for(k=0;k<5;++k){
                nr=r+x[k],nc=c+y[k];
                if(nr<0||nr>3||nc<0||nc>2||a[nr][nc]<0)continue;
                D[i+1][a[nr][nc]]+=D[i][j];
            }
        }
    }
    for(i=0;i<10;++i)ans+=D[n][i];
    printf("%lld",ans);
    return 0;
}
