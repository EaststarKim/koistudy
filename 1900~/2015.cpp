#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct al{
    int nx,e;
}a[400010];
struct tree{
    int x,ml,md;
    long long mcnt,ans;
}b[200010];
struct D{
    int m1,m2,md;
    long long n1,n2,s;
}c[200010];
struct dq{
    int i,s,cnt;
}t[100010];
int st[200010],q[200010],p[200010],chk[200010],lev[200010],d[200010],cnt,l,md;
long long tcnt,ans;
int mod(int i){return i>l?i%l:i;}
void make_al(int s,int e){a[++cnt].nx=st[s],a[cnt].e=e,st[s]=cnt;}
void get_cycle(int s){
    memset(chk,0,sizeof chk);
    for(;;){
        chk[s]=1;
        b[++l].x=s;
        s=p[s];
        if(s==b[1].x)return;
    }
}
void DFS(int s){
    int i;
    for(i=st[s];i;i=a[i].nx){
        if(chk[a[i].e]){
            if(p[s]==a[i].e)continue;
            p[a[i].e]=s;
            get_cycle(s);
            return;
        }
        p[a[i].e]=s;
        chk[a[i].e]=1;
        DFS(a[i].e);
        if(l)return;
    }
}
void trav(int s){
    int i,e;
    long long t=0;
    chk[s]=1;
    for(i=st[s];i;i=a[i].nx)if(!chk[a[i].e]){
        e=a[i].e;
        p[e]=s;
        trav(e);
        if(c[s].md<c[e].md)c[s].md=c[e].md,c[s].s=c[e].s;
    }
    c[s].m1=c[s].m2=-1;
    for(i=st[s];i;i=a[i].nx)if(p[a[i].e]==s){
        e=a[i].e;
        if(c[s].m1<c[e].m1)c[s].m1=c[e].m1;
    }
    for(i=st[s];i;i=a[i].nx)if(p[a[i].e]==s){
        e=a[i].e;
        if(c[e].m1<c[s].m1&&c[s].m2<c[e].m1)c[s].m2=c[e].m1;
    }
    for(i=st[s];i;i=a[i].nx)if(p[a[i].e]==s){
        e=a[i].e;
        if(c[s].m1==c[e].m1){
            t+=c[s].n1*c[e].n1;
            c[s].n1+=c[e].n1;
        }
    }
    ++c[s].m1;
    if(t){
        c[s].md=c[s].m1*2;
        c[s].s=t;
    }
    else{
        for(i=st[s];i;i=a[i].nx)if(p[a[i].e]==s){
            e=a[i].e;
            if(c[s].m2==c[e].m1)c[s].n2+=c[e].n1;
        }
        ++c[s].m2;
        if(c[s].md<=c[s].m1+c[s].m2){
            if(c[s].md<c[s].m1+c[s].m2)c[s].s=0;
            c[s].md=c[s].m1+c[s].m2;
            c[s].s+=c[s].n1*c[s].n2;
        }
    }
    if(!c[s].n1)++c[s].n1;
}
int main(){
    int n,i,j,s,e,sum,m,f=1,r=0,tp=1;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d%d",&s,&e);
        make_al(s,e),make_al(e,s);
    }
    DFS(1);
    memset(p,0,sizeof p);
    for(i=1;i<=l;++i){
        s=b[i].x;
        trav(b[i].x);
        b[i].ml=c[s].m1,b[i].mcnt=c[s].n1,b[i].ans=c[s].s,b[i].md=c[s].md;
    }
    m=l/2+1;
    for(i=2;i<m;++i){
        sum=b[i].ml+i-1;
        while(f<=r&&t[r].s<sum){
            if(tp-1==r)tcnt-=t[--tp].cnt;
            --r;
        }
        t[++r].i=i,t[r].s=sum,t[r].cnt=b[i].mcnt;
        for(;t[tp].s==t[f].s&&tp<=r;++tp)tcnt+=t[tp].cnt;
    }
    for(i=1;i<=l;++i){
        j=mod(i+m-1);
        sum=b[j].ml+m+i-2;
        while(f<=r&&t[r].s<sum){
            if(tp-1==r)tcnt-=t[--tp].cnt;
            --r;
        }
        t[++r].i=j,t[r].s=sum,t[r].cnt=b[j].mcnt;
        for(;t[tp].s==t[f].s&&tp<=r;++tp)tcnt+=t[tp].cnt;
        sum=t[f].s+b[i].ml-i+1;
        if(b[i].md<=sum){
            if(b[i].md<sum)b[i].ans=0;
            b[i].md=sum;
            b[i].ans+=tcnt*b[i].mcnt;
        }
        md=max(md,b[i].md);
        if(t[f].i==mod(i+1))tcnt-=t[f++].cnt;
    }
    for(i=1;i<=l;++i)if(b[i].md==md)ans+=b[i].ans;
    printf("%lld",ans);
    return 0;
}
