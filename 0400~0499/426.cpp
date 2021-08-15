#include <stdio.h>
struct data{
    int x,y;
    data(){}
    data(int x,int y):x(x),y(y){}
}q[500010],w[27][2],p;
char a[310][310];
int d[310][310],t[27],f,r=1;
int x[]={-1,0,1,0},y[]={0,1,0,-1};
int main(){
    int i,j,k,n,m,c;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i){
        scanf("%s",a[i]);
        for(j=0;j<m;++j){
            d[i][j]=1e3;
            if(a[i][j]=='@')q[1]=data(i,j),d[i][j]=0;
            if(64<a[i][j]&&a[i][j]<91)w[a[i][j]-=64][t[a[i][j]]++]=data(i,j);
        }
    }
    while(f<r){
        i=q[++f].x,j=q[f].y;
        if(a[i][j]=='='){
            printf("%d",d[i][j]);
            return 0;
        }
        for(k=0;k<4;++k){
            p=data(i+x[k],j+y[k]);
            c=a[p.x][p.y];
            if(0<c&&c<27)p=w[c][w[c][0].x==p.x&&w[c][0].y==p.y];
            if(c==35||d[p.x][p.y]<=d[i][j]+1)continue;
            d[p.x][p.y]=d[i][j]+1,q[++r]=p;
        }
    }
}
