#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int a,b,x,y;
    bool operator<(const data&r)const{
        if(a==r.a)return x>r.x;
        return a<r.a;
    }
}a[300010];
struct ans{
    int s,e;
    bool operator<(const ans&r)const{
        if(e==r.e)return s>r.s;
        return e>r.e;
    }
}b[300010],t;
int st[100010],cnt,n,m;
int f(int p,int t){
    int i,m=1e8;
    if(p==n)return t;
    for(i=st[p];a[i].a==p&&a[i].x>=t;++i)m=min(m,f(a[i].b,a[i].y));
    return m;
}
int main(){
    int i,q;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i)scanf("%d%d%d%d",&a[i].a,&a[i].b,&a[i].x,&a[i].y);
    sort(a+1,a+m+1);
    for(i=1;i<=m;++i)if(a[i].a!=a[i-1].a)st[a[i].a]=i;
    a[0].x=-1;
    for(i=1;a[i].a==1;++i)if(a[i].x!=a[i-1].x)b[cnt].s=a[i].x,b[cnt++].e=f(1,a[i].x);
    sort(b,b+cnt);
    scanf("%d",&q);
    t.s=1e9;
    for(;q--;){
        scanf("%d",&t.e);
        i=lower_bound(b,b+cnt,t)-b;
        printf("%d\n",i==cnt?-1:b[i].s);
    }
    return 0;
}
