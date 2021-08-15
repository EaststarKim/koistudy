#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
struct data{
    int x,y,t;
}a[210];
int D[210][210][210],ans=1e8;
int dis(int i,int j){return abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);}
int main()
{
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    a[0].x=a[0].y=a[2].x=1;
    a[1].x=a[1].y=a[2].y=n;
    scanf("%d%d%d",&a[3].x,&a[3].y,&a[3].t);
    for(i=0;i<m+3;++i){
        for(j=0;j<m+3;++j){
            for(k=0;k<m+3;++k)D[i][j][k]=1e8;
        }
    }
    D[0][1][3]=dis(2,3)+1;
    if(!a[3].t)D[3][1][2]=dis(0,3)+1,D[0][3][2]=dis(1,3)+1;
    for(i=4;i<m+3;++i){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].t);
        if(a[i].t){
            for(j=0;j<i-1;++j){
                for(k=0;k<i-1;++k){
                    D[i-1][j][i]=min(D[i-1][j][i],D[i-1][j][k]+dis(k,i));
                    D[j][i-1][i]=min(D[j][i-1][i],D[j][i-1][k]+dis(k,i));
                    D[j][k][i]=min(D[j][k][i],D[j][k][i-1]+dis(i-1,i));
                }
            }
        }
        else{
            for(j=0;j<i-1;++j){
                for(k=0;k<i-1;++k){
                    D[i][j][k]=min(D[i][j][k],D[i-1][j][k]+dis(i-1,i)),D[i-1][i][k]=min(D[i-1][i][k],D[i-1][j][k]+dis(j,i)),D[i-1][j][i]=min(D[i-1][j][i],D[i-1][j][k]+dis(k,i));
                    D[i][i-1][k]=min(D[i][i-1][k],D[j][i-1][k]+dis(j,i)),D[j][i][k]=min(D[j][i][k],D[j][i-1][k]+dis(i-1,i)),D[j][i-1][i]=min(D[j][i-1][i],D[j][i-1][k]+dis(k,i));
                    D[i][k][i-1]=min(D[i][k][i-1],D[j][k][i-1]+dis(j,i)),D[j][i][i-1]=min(D[j][i][i-1],D[j][k][i-1]+dis(k,i)),D[j][k][i]=min(D[j][k][i],D[j][k][i-1]+dis(i-1,i));
                }
            }
        }
    }
    for(i=0;i<m+3;++i){
        for(j=0;j<m+3;++j){
            ans=min(ans,D[m+2][i][j]);
            ans=min(ans,D[i][m+2][j]);
            ans=min(ans,D[i][j][m+2]);
        }
    }
    printf("%d",ans-1);
    return 0;
}
