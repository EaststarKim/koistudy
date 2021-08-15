#include <bits/stdc++.h>
using namespace std;
struct data{
    int r,c,h;
    bool operator<(const data&r)const{
        return h<r.h;
    }
}b[1000010],q[1000010];
int a[1010][1010],ts[1010][1010],chk[1010][1010],x[]={-1,0,1,0},y[]={0,1,0,-1},n,m,ans,t;
void ff(int r,int c){
    int i,f=0,p=1;
    q[1]={r,c,0};
    ts[r][c]=t;
    while(f<p){
        r=q[++f].r,c=q[f].c;
        for(i=0;i<4;++i){
            int nr=r+x[i],nc=c+y[i];
            if(a[r][c]<a[nr][nc]&&ts[nr][nc]!=t){
                if(ts[nr][nc])chk[nr][nc]=1;
                else ts[nr][nc]=t,q[++p]={nr,nc,0};
            }
        }
    }
}
int main(){
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)scanf("%d",a[i]+j),b[i*m+j-m]={i,j,a[i][j]};
    }
    sort(b+1,b+n*m+1);
    for(i=1;i<=n*m;++i){
        int r=b[i].r,c=b[i].c;
        for(j=0;j<4;++j){
            int nr=r+x[j],nc=c+y[j];
            if(a[r][c]>a[nr][nc])chk[r][c]+=chk[nr][nc];
        }
        if(chk[r][c])++ans;
        if(!ts[r][c])++t,ff(r,c);
    }
    printf("%d",ans);
    return 0;
}
