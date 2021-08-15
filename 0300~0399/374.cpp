#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
struct data{
    int x,y,z;
    bool operator<(const data&r)const{
        return z>r.z;
    }
};
priority_queue<data> q;
int a[510][510],b[510][510];
int chk[510][510],alev[250010],blev[250010];
int x[]={-1,0,1,0},y[]={0,1,0,-1};
void f(int x1,int y1,int w1,int h1,int a[510][510],int* alev,int ts){
    int i,lev=1,r=0,nx,ny;
    chk[y1][x1]=ts;
    q.push({x1,y1,lev});
    while(!q.empty()){
        data t=q.top();
        q.pop();
        alev[++r]=lev=max(lev,t.z);
        for(i=0;i<4;++i){
            nx=t.x+x[i],ny=t.y+y[i];
            if(nx<1||nx>w1||ny<1||ny>h1||chk[ny][nx]==ts)continue;
            chk[ny][nx]=ts;
            q.push({nx,ny,a[ny][nx]});
        }
    }
    for(++r;r<=w1*h1;++r)alev[r]=1e9;
}
int main(){
    int i,j,r,w1,h1,x1,y1,w2,h2,x2,y2;
    scanf("%d%d%d%d%d",&r,&w1,&h1,&x1,&y1);
    for(i=1;i<=h1;++i){
        for(j=1;j<=w1;++j)scanf("%d",a[i]+j);
    }
    scanf("%d%d%d%d",&w2,&h2,&x2,&y2);
    for(i=1;i<=h2;++i){
        for(j=1;j<=w2;++j)scanf("%d",b[i]+j);
    }
    f(x1,y1,w1,h1,a,alev,1);
    f(x2,y2,w2,h2,b,blev,2);
    int ans=1e9;
    for(i=max(0,r-w2*h2);i<=w1*h1&&i<=r;++i)ans=min(ans,alev[i]+blev[r-i]);
    printf("%d",ans);
    return 0;
}
