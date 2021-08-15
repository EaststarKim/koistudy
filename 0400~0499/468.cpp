#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
struct data{
    int x,y;
    data(){}data(int x,int y):x(x),y(y){}
}a[3][2510];
char t[60][60];
int cnt[3],md[3],n,m,k,ans=1e3;
int x[]={-1,0,1,0},y[]={0,1,0,-1};
int M(int i){return (i+1)%3;}
int d(data a,data b){return abs(a.x-b.x)+abs(a.y-b.y)-1;}
void ff(int r,int c){
    int i,nr,nc;
    t[r][c]=0;
    a[k][++cnt[k]]=data(r,c);
    for(i=0;i<4;++i){
        nr=r+x[i],nc=c+y[i];
        if(nr<0||nr==n||nc<0||nc==m||t[nr][nc]!='X')continue;
        ff(nr,nc);
    }
}
int f(int r,int c){
    if(!t[r][c])return 1e3;
    int i,j,s=1,mn;
    for(i=0;i<3;++i){
        mn=1e3;
        for(j=1;j<=cnt[i];++j)mn=min(mn,d(a[i][j],data(r,c)));
        s+=mn;
    }
    return s;
}
int main(){
    int i,j,l;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i)scanf("%s",t[i]);
    for(i=0;i<n;++i)for(j=0;j<m;++j)if(t[i][j]=='X')ff(i,j),++k;
    for(i=0;i<n;++i)for(j=0;j<m;++j)ans=min(ans,f(i,j));
    for(i=0;i<3;++i){
        md[i]=1e3;
        for(j=1;j<=cnt[i];++j){
            for(l=1;l<=cnt[M(i)];++l)md[i]=min(md[i],d(a[i][j],a[M(i)][l]));
        }
    }
    for(i=0;i<3;++i)ans=min(ans,md[i]+md[M(i)]);
    printf("%d",ans);
    return 0;
}
