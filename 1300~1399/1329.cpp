#include <stdio.h>
int a[110][110],c[110],d[110],p[110],s[110],t[110];
int cmp(int a,int b){
    int k=0,l=0;
    for(;a;a=p[a])s[++k]=a;
    for(;b;b=p[b])t[++l]=b;
    for(;k&&l;--k,--l)if(c[s[k]]<c[t[l]])return 1;
    return 0;
}
void path(int x){
    if(!x)return;
    path(p[x]);
    printf("%d ",x);
}
int main(){
    int i,j,n,m,x,y,z;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i){
        scanf("%d%d%d",&x,&y,&z);
        a[x][y]=a[y][x]=z;
    }
    for(i=1;i<=n;++i)scanf("%d",&x),c[x]=i,d[i]=1e8;
    d[1]=1;
    for(i=1;i<n;++i){
        m=1e7;
        for(j=1;j<=n;++j)if(d[j]&&m>d[j])x=j,m=d[j];
        for(j=1;j<=n;++j)if(a[x][j]){
            z=m+a[x][j];
            if(d[j]==z&&cmp(x,j))p[j]=x;
            if(d[j]>z)d[j]=z,p[j]=x;
        }
        d[x]=0;
    }
    path(n);
    return 0;
}
