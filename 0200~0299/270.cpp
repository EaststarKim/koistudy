#include <stdio.h>
#include <string.h>
struct que{
    int r,c;
    que(){}
    que(int r,int c):r(r),c(c){}
}q[2510],p;
int a[51][51],chk[51][51],n,m,cnt,s,mx;
int dr[]={0,-1,0,1},dc[]={-1,0,1,0},b[]={1,2,4,8},w;
char d[]="WNES";
int f(int x,int y){
    int i,nr,nc,f=0,r=1;
    q[1]=que(x,y);
    chk[x][y]=1;
    while(f<r){
        x=q[++f].r,y=q[f].c;
        for(i=0;i<4;++i){
            nr=x+dr[i],nc=y+dc[i];
            if(nr<1||nr>n||nc<1||nc>m||chk[nr][nc]||a[x][y]&b[i])continue;
            chk[nr][nc]=1;
            q[++r]=que(nr,nc);
        }
    }
    return r;
}
int main(){
    int i,j,k,r,c;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)scanf("%d",a[i]+j);
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)if(!chk[i][j]){
            ++cnt,s=f(i,j);
            if(mx<s)mx=s;
        }
    }
    printf("%d\n%d\n",cnt,mx);
    mx=0;
    for(i=1;i<=m;++i){
        for(j=n;j>0;--j){
            for(k=0;k<4;++k)if(a[j][i]&b[k]){
                r=j+dr[k],c=i+dc[k];
                if(r<1||r>n||c<1||c>m)continue;
                memset(chk,0,sizeof chk);
                a[j][i]-=b[k];
                s=f(j,i);
                if(mx<s)mx=s,p=que(j,i),w=k;
                a[j][i]+=b[k];
            }
        }
    }
    printf("%d\n%d% d %c",mx,p.r,p.c,d[w]);
    return 0;
}
