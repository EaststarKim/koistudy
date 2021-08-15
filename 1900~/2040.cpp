#include <stdio.h>
char a[1510][1510],b[9]="JAEMIN";
long long D[9][1510][1510],ans;
int x[]={-1,-1,0,1,1,1,0,-1},y[]={0,1,1,1,0,-1,-1,-1};
int main(){
    int i,j,k,m,h,w,r,c;
    scanf("%d%d",&h,&w);
    for(i=0;i<h;++i)scanf("%s",a[i]);
    for(i=0;i<h;++i){
        for(j=0;j<w;++j)if(a[i][j]==b[0])D[0][i][j]=1;
    }
    for(i=1;i<6;++i){
        for(j=0;j<h;++j){
            for(k=0;k<w;++k)if(D[i-1][j][k]){
                for(m=0;m<8;++m){
                    r=j+x[m],c=k+y[m];
                    if(r<0||r==h||c<0||c==w||a[r][c]!=b[i])continue;
                    D[i][r][c]+=D[i-1][j][k];
                }
            }
        }
    }
    for(i=0;i<h;++i){
        for(j=0;j<w;++j)ans+=D[5][i][j];
    }
    printf("%lld",ans);
    return 0;
}
