#include <stdio.h>
struct data{
    int x,y,z;
}q[1000010],p;
int s[110][110][110],n,f,r=1;
int a[6]={1,-1},b[6]={0,0,1,-1},c[6]={0,0,0,0,1,-1};
int main()
{
    int i,j,k,x,y,z,t,nx,ny,nz;
    scanf("%d",&n);
    scanf("%d%d%d%d",&x,&y,&z,&t);
    s[x][y][z]=t;
    q[1].x=x,q[1].y=y,q[1].z=z;
    while(f<r){
        p=q[++f];
        for(i=0;i<6;++i){
            nx=p.x+a[i],ny=p.y+b[i],nz=p.z+c[i];
            if(nx<1||nx>n||ny<1||ny>n||nz<1||nz>n||s[nx][ny][nz])continue;
            s[nx][ny][nz]=s[p.x][p.y][p.z]-1;
            if(s[nx][ny][nz]>1)q[++r].x=nx,q[r].y=ny,q[r].z=nz;
        }
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            for(k=1;k<=n;++k)printf("%d ",s[i][j][k]);
            puts("");
        }
        puts("");
    }
    return 0;
}
