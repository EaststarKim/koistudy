#include <stdio.h>
int a[510][510],n,m;
long long bit[510][510],y,mx;
long long getsum(int r,int c){
    long long s=0;
    for(;r;r-=r&-r){
        for(int t=c;t;t-=t&-t)s+=bit[r][t];
    }
    return s;
}
void update(int r,int c,int v){
    for(;r<=n;r+=r&-r){
        for(int t=c;t<=m;t+=t&-t)bit[r][t]+=v;
    }
}
int main(){
    int i,j,q,x,z,w,l,h,mi,mj;
    scanf("%d%d%d",&n,&m,&q);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)scanf("%d",a[i]+j),update(i,j,a[i][j]);
    }
    for(;q--;){
        scanf("%d%lld",&x,&y);
        if(x<2)scanf("%d%d",&z,&w),update(y,z,w-a[y][z]),a[y][z]=w;
        else{
            mx=-1;
            j=0;
            for(i=n;i;--i){
                l=j+1,h;
                for(j=m;l<=j;){
                    h=(l+j)/2;
                    if(getsum(i,h)>y)j=h-1;
                    else l=h+1;
                }
                if(j&&mx<getsum(i,j))mx=getsum(mi=i,mj=j);
            }
            if(mx<0)puts("-1");
            else printf("%d %d\n",mi,mj);
        }
    }
    return 0;
}
