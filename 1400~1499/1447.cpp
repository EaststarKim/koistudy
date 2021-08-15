#include <stdio.h>
#include <queue>
using namespace std;
struct data{
    int e,t,nx;
}a[2000010];
int st[100010],cnt;
void make_al(int s,int e,int t){a[++cnt]={e,t,st[s]},st[s]=cnt;}
struct que{
    int s,t;
    bool operator<(const que&r)const{
        return t>r.t;
    }
};
priority_queue<que> q;
int m1[100010],m2[100010];
void sol(){
    int i;
    while(!q.empty()){
        que p=q.top();
        q.pop();
        if(m2[p.s]!=p.t)continue;
        for(i=st[p.s];i;i=a[i].nx){
            int s=p.t+a[i].t,flag=0;
            if(m1[a[i].e]>s){
                if(m2[a[i].e]>m1[a[i].e])m2[a[i].e]=m1[a[i].e],flag=1;
                m1[a[i].e]=s;
            }
            else if(m2[a[i].e]>s)m2[a[i].e]=s,flag=1;
            if(flag)q.push({a[i].e,m2[a[i].e]});
        }
    }
}
int main(){
    int i,n,m,k,s,e,t;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=m;++i){
        scanf("%d%d%d",&s,&e,&t);
        make_al(s,e,t);
        make_al(e,s,t);
    }
    for(i=0;i<n;++i)m1[i]=m2[i]=2e9;
    for(i=1;i<=k;++i){
        scanf("%d",&s);
        q.push({s,m1[s]=m2[s]=0});
    }
    sol();
    printf("%d",m2[0]);
    return 0;
}
