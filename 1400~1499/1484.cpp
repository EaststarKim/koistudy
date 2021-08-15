#include <stdio.h>
struct al{
    int nx,e;
}a[20010];
int st[10010],cnt,n;
int chk[10010],s[10010],t[10010],ans[10010];
void make_al(int s,int e){a[++cnt]={st[s],e},st[s]=cnt;}
void f(int p){
    int i;
    chk[p]=1;
    s[p]=1;
    for(i=st[p];i;i=a[i].nx)if(!chk[a[i].e]){
        f(a[i].e);
        s[p]+=s[a[i].e];
    }
}
void g(int p){
    int i;
    chk[p]=1;
    if(t[p]>n/2)ans[p]=1;
    for(i=st[p];i;i=a[i].nx)if(!chk[a[i].e]){
        t[a[i].e]=t[p]+s[p]-s[a[i].e];
        g(a[i].e);
        if(s[a[i].e]>n/2)ans[p]=1;
    }
}
int main(){
    int i,s,e;
    scanf("%d",&n);
    for(i=1;i<n;++i){
        scanf("%d%d",&s,&e);
        make_al(s,e);
        make_al(e,s);
    }
    f(1);
    for(i=1;i<=n;++i)chk[i]=0;
    g(1);
    for(i=1;i<=n;++i)if(!ans[i])printf("%d\n",i);
    return 0;
}
