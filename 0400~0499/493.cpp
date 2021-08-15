#include <stdio.h>
#include <string.h>
int x[260],y[260],z[260],w[260],a[260][260],right[260],vis[260],n,ans;
bool bet(int s,int m,int e){return s<=m&&m<=e;}
int augment(int i){
    int j;
    for(j=1;j<=n;++j)if(a[i][j]&&!vis[j]){
        vis[j]=1;
        if(!right[j]||augment(right[j])){
            right[j]=i;
            return 1;
        }
    }
    return 0;
}
int main(){
    int i,j,t;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d%d%d%d",x+i,y+i,z+i,w+i);
        if(x[i]>z[i])t=x[i],x[i]=z[i],z[i]=t;
        if(y[i]>w[i])t=y[i],y[i]=w[i],w[i]=t;
        for(j=1;j<i;++j){
            if(x[i]==z[i]&&y[j]==w[j]){
                if(bet(x[j],x[i],z[j])&&bet(y[i],y[j],w[i]))a[i][j]=a[j][i]=1;
            }
            if(y[i]==w[i]&&x[j]==z[j]){
                if(bet(x[i],x[j],z[i])&&bet(y[j],y[i],w[j]))a[i][j]=a[j][i]=1;
            }
        }
    }
    for(i=1;i<=n;++i){
        memset(vis,0,sizeof vis);
        ans+=augment(i);
    }
    printf("%d",n-ans/2);
    return 0;
}
