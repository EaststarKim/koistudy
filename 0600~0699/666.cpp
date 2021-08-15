#include <stdio.h>
#include <algorithm>
struct data{
    int s,e;
    double p;
    bool operator<(const data&r)const{
        return s<r.s;
    }
}a[100010];
double p[1010],mx;
int st[1010],chk[1010];
void path(int k){
    if(k==1){
        printf("1 ");
        return;
    }
    path(chk[k]);
    printf("%d ",k);
}
int main()
{
    int i,j,n,m,mi;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)scanf("%d%d%lf",&a[i].s,&a[i].e,&a[i].p);
    std::sort(a,a+m+1);
    for(i=1;i<=m;++i){
        if(a[i].s!=a[i-1].s)st[a[i].s]=i;
    }
    for(i=2;i<=n;++i)p[i]=-1;
    p[1]=1;
    for(i=1;i<=n;++i){
        mx=-1;
        for(j=1;j<=n;++j){
            if(p[j]>mx)mx=p[j],mi=j;
        }
        for(j=st[mi];j<=m&&a[j].s==mi;++j){
            if(p[a[j].e]>-2&&p[a[j].e]<p[mi]*a[j].p)p[a[j].e]=p[mi]*a[j].p,chk[a[j].e]=mi;
        }
        p[mi]=-2;
    }
    path(n);
    return 0;
}
