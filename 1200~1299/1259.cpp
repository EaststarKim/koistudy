#include <stdio.h>
int a[21][21],D[21][21][21][21][21],n,l,ans;
int dx[]={-1,-1,0,1,1,1,0,-1},dy[]={0,1,1,1,0,-1,-1,-1};
int f(int p,int r,int c,int x,int y){
    int i,j,nr,nc,nx,ny,&s=D[p][r][c][x][y];
    if(s)return s;
    if(!p)return s=1;
    for(i=0;i<8;++i){
        nr=r+dx[i],nc=c+dy[i];
        if(nr<1||nr>n||nc<1||nc>n)continue;
        for(j=0;j<8;++j){
            nx=x+dx[j],ny=y+dy[j];
            if(nx<1||nx>n||ny<1||ny>n||a[nr][nc]!=a[nx][ny])continue;
            s+=f(p-2,nr,nc,nx,ny);
        }
    }
    return s;
}
int main(){
    int i,j,k,l,r,c,x,y;
    scanf("%d%d",&n,&l);
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j)scanf("%d",a[i]+j);
    }
    if(l%2){
        for(i=1;i<=n;++i){
            for(j=1;j<=n;++j)ans+=f(l-1,i,j,i,j);
        }
    }
    else{
        for(i=1;i<=n;++i){
            for(j=1;j<=n;++j){
                for(k=0;k<8;++k){
                    r=i+dx[k],c=j+dy[k];
                    if(r<1||r>n||c<1||c>n||a[i][j]!=a[r][c])continue;
                    ans+=f(l-2,i,j,r,c);
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
