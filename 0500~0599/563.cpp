#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int t,x,y;
    bool operator<(const data&r)const{
        return x<r.x;
    }
}a[20010];
int st[10010],gp[2],g[10010],gap[10010],chk[10010],D[10010],m,gs;
void f(int nod){
    int i;
    chk[nod]=1;
    for(i=st[nod];a[i].x==nod;++i){
        if(chk[a[i].y]){
            if(a[i].t<0&&g[a[i].y]==g[nod])gs=-1;
            else if(a[i].t>0&&g[a[i].y]!=g[nod])gs=-1;
            if(gs<0)return;
            continue;
        }
        if(a[i].t<0)++gp[g[a[i].y]=!g[nod]];
        else ++gp[g[a[i].y]=g[nod]];
        f(a[i].y);
        if(gs<0)return;
    }
    gs=gp[0]-gp[1];
    if(gs<0)gs=-gs;
}
int main()
{
    int i,j,k,n,s,p;
    for(i=1;i<6;++i){
        scanf("%d%d",&n,&m);
        m*=2;
        for(j=1;j<=m;j+=2){
            scanf("%d%d%d",&a[j].t,&a[j].x,&a[j].y);
            a[j+1].t=a[j].t;
            a[j+1].x=a[j].y;
            a[j+1].y=a[j].x;
        }
        sort(a+1,a+m+1);
        s=p=0;
        for(j=1;j<=n;++j)st[j]=chk[j]=g[j]=D[j]=0;
        for(j=1;j<=m;++j){
            if(a[j-1].x!=a[j].x)st[a[j].x]=j;
        }
        for(j=1;j<=n;++j)if(!chk[j]){
            gs=gp[1]=0;
            gp[0]=1;
            f(j);
            if(gs<0)break;
            s+=gap[++p]=gs;

        }
        if(j<=n){
            puts("-1");
            continue;
        }
        D[0]=1;
        for(j=1;j<=p;++j){
            for(k=n-gap[j];k>=0;--k){
                if(D[k])D[k+gap[j]]=1;
            }
        }
        for(j=s/2;!D[j];--j);
        printf("%d\n",s-j*2);
    }
    return 0;
}
