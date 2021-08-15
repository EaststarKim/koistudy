#include <stdio.h>
int m1[150010],m2[150010];
struct data{
    int x,y;
}a[150010][2];
int chk[150010][2];
int c[150010][2],cl[150010],t;
void cycle(int x,int y){
    data p={x,y};
    cl[c[x][y]=++t]=1;
    chk[x][y]=2;
    for(;;){
        p=a[p.x][p.y];
        if(p.x==x&&p.y==y)return;
        ++cl[c[p.x][p.y]=t];
        chk[p.x][p.y]=2;
    }
}
void dfs(int x,int y){
    if(chk[x][y]){
        if(chk[x][y]<2&&!c[x][y])cycle(x,y);
        return;
    }
    chk[x][y]=1;
    dfs(a[x][y].x,a[x][y].y);
    if(chk[a[x][y].x][a[x][y].y]>1)chk[x][y]=2;
}
int d[150010][2],e[150010][2];
void dis(int x,int y,int d[150010][2]){
    if(chk[x][y])return;
    chk[x][y]=1;
    dis(a[x][y].x,a[x][y].y,d);
    if(d[a[x][y].x][a[x][y].y])d[x][y]=d[a[x][y].x][a[x][y].y]+1;
}
int main(){
    int i,n,m,p,q,x,y,g;
    scanf("%d%d%d",&n,&m,&p);
    ++p;
    for(i=1;i<=m;++i){
        scanf("%d%d",&x,&y);
        ++x,++y;
        if(!m1[x])m1[x]=y;
        else if(!m2[x])m2[x]=y;
        if(!m1[y])m1[y]=x;
        else if(!m2[y])m2[y]=x;
    }
    for(i=1;i<=n;++i){
        if(m2[m1[i]]&&m1[m1[i]]==i)a[i][0]={m1[i],1};
        else a[i][0]={m1[i],0};
        if(m2[i]){
            if(m2[m2[i]]&&m1[m2[i]]==i)a[i][1]={m2[i],1};
            else a[i][1]={m2[i],0};
        }
    }
    for(i=1;i<=n;++i){
        if(!chk[i][0])dfs(i,0);
        if(!chk[i][1])dfs(i,1);
    }
    for(i=1;i<=n;++i)chk[i][0]=chk[i][1]=0;
    chk[p][0]=d[p][0]=1;
    for(i=1;i<=n;++i)if(!chk[i][0])dis(i,0,d);
    for(i=1;i<=n;++i)chk[i][0]=chk[i][1]=0;
    chk[p][1]=e[p][1]=1;
    for(i=1;i<=n;++i)if(!chk[i][0])dis(i,0,e);
    scanf("%d",&q);
    for(;q--;){
        scanf("%d",&g);
        ++g;
        int ans=0;
        for(i=1;i<=n;++i){
            int flag=0;
            if(d[i][0]&&d[i][0]<=g){
                if(c[p][0])flag|=((g-d[i][0])%cl[c[p][0]]==0);
                if(d[i][0]==g)flag|=1;
            }
            if(e[i][0]&&e[i][0]<=g){
                if(c[p][1])flag|=((g-e[i][0])%cl[c[p][1]]==0);
                if(e[i][0]==g)flag|=1;
            }
            ans+=flag;
        }
        printf("%d\n",ans);
    }
    return 0;
}
