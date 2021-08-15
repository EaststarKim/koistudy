#include <stdio.h>
#include <algorithm>
using namespace std;
int a[260][260],d[260][260];
int x[]={-1,0,1,0},y[]={0,1,0,-1};
int main(){
    int i,j,k,n,s,t,r,c,er,ec,mn;
    scanf("%d%d%d",&s,&t,&n);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            scanf("%d",a[i]+j);
            d[i][j]=1e8;
            if(a[i][j]==2)d[i][j]=1;
            if(a[i][j]==3)er=i,ec=j;
            if(a[i][j]==1)a[i][j]=s;
            else a[i][j]=t;
        }
    }
    while(1){
        mn=1e8;
        for(i=1;i<=n;++i)for(j=1;j<=n;++j)if(d[i][j])mn=min(mn,d[i][j]);
        if(mn==d[er][ec])break;
        for(i=1;i<=n;++i){
            for(j=1;j<=n;++j)if(d[i][j]==mn){
                for(k=0;k<4;++k){
                    r=i+x[k],c=j+y[k];
                    d[r][c]=min(d[r][c],mn+a[r][c]);
                }
                d[i][j]=0;
            }
        }
    }
    printf("%d",mn-1);
    return 0;
}
