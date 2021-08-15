#include <stdio.h>
#include <algorithm>
using namespace std;
char c[210][80];
int a[2][210][80],q[4010][2],w,h,t,ans;
int x[]={-1,0,1,0},y[]={0,1,0,-1};
void bfs(int i,int j,int d[210][80]){
    int k,nr,nc,f=0,r=1;
    q[1][0]=i,q[1][1]=j;
    d[i][j]=1;
    while(f<r){
        i=q[++f][0],j=q[f][1];
        for(k=0;k<4;++k){
            nr=i+x[k],nc=j+y[k];
            if(nr&&nc&&nr<h*2&&nc<w*2&&c[nr][nc]==' '){
                nr+=x[k],nc+=y[k];
                if(!d[nr][nc])d[nr][nc]=d[i][j]+1,q[++r][0]=nr,q[r][1]=nc;
            }
        }
    }
}
int main(){
    int i,j;
    scanf("%d%d\n",&w,&h);
    for(i=0;i<=h*2;++i)fgets(c[i],sizeof c[i],stdin);
    for(i=1;i<w*2;i+=2)if(c[0][i]==' ')bfs(1,i,a[t++]);
    for(i=1;i<w*2;i+=2)if(c[h*2][i]==' ')bfs(h*2-1,i,a[t++]);
    for(i=1;i<h*2;i+=2)if(c[i][0]==' ')bfs(i,1,a[t++]);
   for(i=1;i<h*2;i+=2)if(c[i][w*2]==' ')bfs(i,w*2-1,a[t++]);
    for(i=1;i<h*2;i+=2){
        for(j=1;j<w*2;j+=2)ans=max(ans,min(a[0][i][j],a[1][i][j]));
    }
    printf("%d",ans);
    return 0;
}
