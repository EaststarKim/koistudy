#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
struct data{
    int r,c,d;
    data(){}
    data(int r,int c,int d):r(r),c(c),d(d){}
    bool operator<(const data&r)const{
        return d>r.d;
    }
}h[9000];
int r[790],c[790],a[790][31][27],b[790][31][27],ro,co,n,ans=2e9;
int q[900][2],x[]={-2,-1,1,2,2,1,-1,-2},y[]={1,2,2,1,-1,-2,-2,-1};
void bfs(int i,int j,int a[31][27]){
    int k,l,f=0,r=1,nr,nc;
    for(k=1;k<=ro;++k){
        for(l=1;l<=co;++l)a[k][l]=1e5;
    }
    a[i][j]=0;
    q[1][0]=i,q[1][1]=j;
    while(f<r){
        i=q[++f][0],j=q[f][1];
        for(k=0;k<8;++k){
            nr=i+x[k],nc=j+y[k];
            if(nr<1||nr>ro||nc<1||nc>co||a[nr][nc]<=a[i][j]+1)continue;
            a[nr][nc]=a[i][j]+1;
            q[++r][0]=nr,q[r][1]=nc;
        }
    }
}
void dijkstra(int t,int b[31][27]){
    int i,j,k,l,nr,nc,p=0;
    for(k=1;k<=ro;++k){
        for(l=1;l<=co;++l){
            b[k][l]=a[t][k][l]+max(abs(k-r[0]),abs(l-c[0]));
            h[p++]=data(k,l,b[k][l]);
            push_heap(h,h+p);
        }
    }
    for(k=1;k<ro*co;++k){
        i=h[0].r,j=h[0].c;
        pop_heap(h,h+p);
        --p;
        for(l=0;l<8;++l){
            nr=i+x[l],nc=j+y[l];
            if(nr<1||nr>ro||nc<1||nc>co||b[nr][nc]<=b[i][j]+1)continue;
            b[nr][nc]=b[i][j]+1;
            h[p++]=data(nr,nc,b[nr][nc]);
            push_heap(h,h+p);
        }
    }
}
int main(){
    int i,j,k,s,mn;
    char t;
    scanf("%d%d",&ro,&co);
    while(scanf("%s %d ",&t,&r[n])==2)c[n++]=t-64;
    if(n<2){
        puts("0");
        return 0;
    }
    for(i=1;i<n;++i)bfs(r[i],c[i],a[i]);
    for(i=1;i<n;++i)dijkstra(i,b[i]);
    for(i=1;i<=ro;++i){
        for(j=1;j<=co;++j){
            s=0,mn=2e9;
            for(k=1;k<n;++k){
                s+=a[k][i][j];
                mn=min(mn,b[k][i][j]-a[k][i][j]);
            }
            ans=min(ans,s+mn);
        }
    }
    printf("%d",ans);
    return 0;
}
