#include <bits/stdc++.h>
using namespace std;
struct al{
    int e,nx;
}a[1000010];
int st[500010],t;
void make_al(int s,int e){a[++t]={e,st[s]},st[s]=t;}
int q[500010],d[500010],p[500010],m,ans;
int bfs(int n){
    int i,f=0,r=1;
    memset(d,0,sizeof d);
    d[q[1]=n]=1;
    while(f<r){
        n=q[++f];
        for(i=st[n];i;i=a[i].nx)if(!d[a[i].e]){
            d[q[++r]=a[i].e]=d[n]+1,p[a[i].e]=n;
            if(d[m]<d[a[i].e])m=a[i].e;
        }
    }
    return m;
}
int main(){
    int i,n,s,e;
    scanf("%d",&n);
    for(i=1;i<n;++i){
        scanf("%d%d",&s,&e);
        make_al(s,e);
        make_al(e,s);
    }
    bfs(bfs(1));
    for(i=(d[m]-1)/2;i--;)m=p[m];
    printf("%d",m);
    return 0;
}
