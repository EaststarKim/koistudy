#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int e,t,nx;
}a[200010];
int st[100010],cnt;
void make_al(int s,int e,int t){a[++cnt]={e,t,st[s]},st[s]=cnt;}
int lev[100010],spt[100010][17],mx[100010][17],mn[100010][17];
void dfs(int p){
    int i;
    for(i=1;i<17;++i){
        spt[p][i]=spt[spt[p][i-1]][i-1];
        mx[p][i]=max(mx[p][i-1],mx[spt[p][i-1]][i-1]);
        mn[p][i]=min(mn[p][i-1],mn[spt[p][i-1]][i-1]);
    }
    for(i=st[p];i;i=a[i].nx)if(!lev[a[i].e]){
        lev[a[i].e]=lev[p]+1;
        spt[a[i].e][0]=p;
        mx[a[i].e][0]=mn[a[i].e][0]=a[i].t;
        dfs(a[i].e);
    }
}
void f(int x,int y){
    int i,ansmx=0,ansmn=1e9;
    if(lev[x]<lev[y])swap(x,y);
    for(i=17;i--;)if(lev[x]-lev[y]>=(1<<i))ansmx=max(ansmx,mx[x][i]),ansmn=min(ansmn,mn[x][i]),x=spt[x][i];
    if(x==y){
        printf("%d %d\n",ansmn,ansmx);
        return;
    }
    for(i=17;i--;)if(spt[x][i]!=spt[y][i]){
        ansmx=max(ansmx,mx[x][i]),ansmn=min(ansmn,mn[x][i]),x=spt[x][i];
        ansmx=max(ansmx,mx[y][i]),ansmn=min(ansmn,mn[y][i]),y=spt[y][i];
    }
    ansmx=max(ansmx,mx[x][0]),ansmn=min(ansmn,mn[x][0]);
    ansmx=max(ansmx,mx[y][0]),ansmn=min(ansmn,mn[y][0]);
    printf("%d %d\n",ansmn,ansmx);
}
int main(){
    int i,n,s,e,t;
    scanf("%d",&n);
    for(i=1;i<n;++i){
        scanf("%d%d%d",&s,&e,&t);
        make_al(s,e,t);
        make_al(e,s,t);
    }
    lev[1]=1;
    dfs(1);
    scanf("%d%d",&s,&e);
    f(s,e);
    return 0;
}
