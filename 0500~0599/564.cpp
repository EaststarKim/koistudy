#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int s,e;
    bool operator<(const data&r)const{
        return s<r.s;
    }
}a[600010];
struct d{
    int a,b,l;
}D[300010];
int st[300010],q[300010],chk[300010],n,k;
void BFS(){
    int i,p,f=0,r=1;
    q[1]=chk[1]=1;
    while(f<r){
        p=q[++f];
        for(i=st[p];a[i].s==p;++i)if(!chk[a[i].e])q[++r]=a[i].e,chk[a[i].e]=r;
    }
}
int main(){
    int i,j,m,s,t,x,y;
    scanf("%d%d",&n,&k);
    for(i=1;i<n;++i){
        scanf("%d%d",&x,&y);
        a[i].s=a[n+i-1].e=x,a[i].e=a[n+i-1].s=y;
    }
    m=n*2-1;
    sort(a+1,a+m);
    for(i=1;i<m;++i)if(a[i-1].s!=a[i].s)st[a[i].s]=i;
    BFS();
    for(i=n;i>0;--i){
        t=q[i];
        if(t>1&&a[st[t]+1].s!=t)D[t].a=0,D[t].b=1,D[t].l=0;
        else{
            s=0;
            for(j=st[t];a[j].s==t;++j)if(chk[t]<chk[a[j].e])s+=D[a[j].e].b;
            D[t].a=s,D[t].l=0;
            for(j=st[t];a[j].s==t;++j)if(chk[t]<chk[a[j].e]&&D[a[j].e].l+1<=k){
                if(s-D[a[j].e].b+D[a[j].e].a<D[t].a)D[t].a=s-D[a[j].e].b+D[a[j].e].a,D[t].l=D[a[j].e].l+1;
                else if(s-D[a[j].e].b+D[a[j].e].a==D[t].a&&D[t].l>D[a[j].e].l+1)D[t].l=D[a[j].e].l+1;
            }
            D[t].b=D[t].a+1;
            x=y=0,D[0].l=1e9;
            for(j=st[t];a[j].s==t;++j)if(chk[t]<chk[a[j].e]&&D[a[j].e].a<D[a[j].e].b&&D[a[j].e].l<D[x].l)x=a[j].e;
            for(j=st[t];a[j].s==t;++j)if(chk[t]<chk[a[j].e]&&a[j].e!=x&&D[a[j].e].a<D[a[j].e].b&&D[a[j].e].l<D[y].l)y=a[j].e;
            if(x&&y&&D[x].l+D[y].l+2<=k)D[t].b=s-1;
        }
    }
    printf("%d",D[1].b);
    return 0;
}
