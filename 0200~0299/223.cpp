#include <stdio.h>
struct al{
    int e,nx;
}a[1111111];
int st[100010],d[100010],cnt,ans;
void make_al(int s,int e){a[++cnt].nx=st[s],a[cnt].e=e,st[s]=cnt;}
void f(int x,int p){
    int i;
    if(d[x]){
        if(d[p]-d[x]>1)++ans;
        return;
    }
    d[x]=d[p]+1;
    for(i=st[x];i;i=a[i].nx)f(a[i].e,x);
}
int main(){
    int i,n,m,s,e;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i){
        scanf("%d%d",&s,&e);
        make_al(s,e),make_al(e,s);
    }
    for(i=1;i<=n;++i)if(!d[i])f(i,0);
    printf("%d",ans);
    return 0;
}
