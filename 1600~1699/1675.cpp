#include <stdio.h>
#define M 1000000000
struct al{
    int e,nx;
}a1[100010],a2[100010];
int st1[10010],st2[10010],n1,n2;
void make_al(al *a,int &n,int *st,int s,int e){a[++n]={e,st[s]},st[s]=n;}
int chk1[10010],chk2[10010];
void dfs(int *chk,al *a,int *st,int p){
    int i;
    chk[p]=1;
    for(i=st[p];i;i=a[i].nx)if(!chk[a[i].e])dfs(chk,a,st,a[i].e);
}
int vis[10010],in[10010],flag;
void find_cycle(int p){
    int i;
    if(p==2)return;
    vis[p]=1;
    for(i=st1[p];i;i=a1[i].nx)if(chk1[a1[i].e]&&chk2[a1[i].e]){
        if(vis[a1[i].e]==1){
            flag=1;
            return;
        }
        ++in[a1[i].e];
        if(!vis[a1[i].e])find_cycle(a1[i].e);
        if(flag)return;
    }
    vis[p]=2;
}
int t[10010];
long long D[10010];
int main(){
    int i,j,n,m,s,e;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i){
        scanf("%d%d",&s,&e);
        make_al(a1,n1,st1,s,e);
        make_al(a2,n2,st2,e,s);
    }
    dfs(chk1,a1,st1,1);
    dfs(chk2,a2,st2,2);
    find_cycle(1);
    if(flag){
        puts("OH NO");
        return 0;
    }
    D[1]=1;
    for(;;){
        for(i=1;i<=n;++i)if(chk1[i]&&chk2[i]){
            if(!in[i])break;
        }
        if(i>n)break;
        in[i]=-1;
        for(j=st1[i];j;j=a1[j].nx)if(chk1[a1[j].e]&&chk2[a1[j].e]){
            --in[a1[j].e];
            D[a1[j].e]+=D[i];
            if(D[a1[j].e]>=M||t[i])D[a1[j].e]%=M,t[a1[j].e]=1;
        }
    }
    if(t[2])printf("%09d",D[2]%M);
    else printf("%d",D[2]);
    return 0;
}
