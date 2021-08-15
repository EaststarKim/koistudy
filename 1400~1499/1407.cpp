#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int s,e;
    bool operator<(const data&r)const{
        return s<r.s;
    }
}a[200010];
int st[100010],b[100010],D[100010][2],chk[100010][2],p[100010];
void dfs(int s){
    int i;
    for(i=st[s];a[i].s==s;++i)if(!p[a[i].e]){
        p[a[i].e]=s;
        dfs(a[i].e);
    }
}
void f(int s,int t){
    int i;
    chk[s][t]=1;
    for(i=st[s];a[i].s==s;++i){
        if(p[a[i].e]==s&&!chk[a[i].e][0])f(a[i].e,0);
        if(p[a[i].e]==s&&!chk[a[i].e][1])f(a[i].e,1);
        if(t&&p[a[i].e]==s)D[s][1]+=D[a[i].e][0];
        else if(p[a[i].e]==s)D[s][0]+=max(D[a[i].e][0],D[a[i].e][1]);
    }
    if(t)D[s][t]+=b[s];
}
int main(){
    int i,n,m;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",b+i);
    m=n*2-2;
    for(i=1;i<m;i+=2){
        scanf("%d%d",&a[i].s,&a[i].e);
        a[i+1]=a[i];
        swap(a[i+1].s,a[i+1].e);
    }
    sort(a+1,a+m+1);
    for(i=1;i<=m;++i)if(a[i].s!=a[i-1].s)st[a[i].s]=i;
    p[1]=-1;
    dfs(1);
    f(1,0);
    f(1,1);
    printf("%d",max(D[1][0],D[1][1]));
    return 0;
}
