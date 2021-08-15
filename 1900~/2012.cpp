#include <stdio.h>
#include <queue>
using namespace std;
struct al{
    int nx,e,t,h;
    al(){}al(int nx,int e,int t,int h):nx(nx),e(e),t(t),h(h){}
}a[20010];
struct que{
    int s,t,h;
    que(){}que(int s,int t,int h):s(s),t(t),h(h){}
    bool operator<(const que&r)const{
        return t>r.t;
    }
}p;
int st[2010],chk[2010][210],cnt;
priority_queue<que> q;
void make_al(int s,int e,int t,int h){a[++cnt]=al(st[s],e,t,h),st[s]=cnt;}
int main(){
    int i,k,n,m,s,e,t,h;
    scanf("%d%d%d",&k,&n,&m);
    for(i=1;i<=m;++i){
        scanf("%d%d%d%d",&s,&e,&t,&h);
        make_al(s,e,t,h),make_al(e,s,t,h);
    }
    scanf("%d%d",&s,&e);
    q.push(que(s,0,k));
    while(!q.empty()){
        p=q.top();
        q.pop();
        if(p.s==e){
            printf("%d",p.t);
            return 0;
        }
        if(chk[p.s][p.h])continue;
        chk[p.s][p.h]=1;
        for(i=st[p.s];i;i=a[i].nx)if(p.h>a[i].h)q.push(que(a[i].e,p.t+a[i].t,p.h-a[i].h));
    }
    puts("-1");
    return 0;
}
