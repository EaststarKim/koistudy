#include <stdio.h>
#include <queue>
using namespace std;
int a[31][31],b[3],t[3],d[27000];
struct que{
    int p,d;
    que(){}
    que(int p,int d):p(p),d(d){}
    bool operator<(const que&r)const{
        return d>r.d;
    }

};
priority_queue<que> q;
int main(){
    int i,j,n,s,e,p;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        for(j=0;j<n;++j)scanf("%d",a[i]+j);
    }
    for(i=0;i<n*n*n;++i)d[i]=2e9;
    t[0]=1,t[1]=n,t[2]=n*n;
    scanf("%d%d",&s,&e);
    s=(s-1)*(n*n+n+1),e=(e-1)*(n*n+n+1);
    q.push(que(s,0)),d[s]=0;
    while(!q.empty()){
        s=q.top().p;
        q.pop();
        if(s==e)break;
        b[0]=s%n,b[1]=s/n%n,b[2]=s/n/n;
        for(i=0;i<3;++i){
            if(i==1&&b[1]==b[0])continue;
            if(i==2&&(b[2]==b[0]||b[2]==b[1]))continue;
            for(j=0;j<n;++j)if(a[b[i]][j]){
                if((j==b[0]||j==b[1])&&i)continue;
                p=s+t[i]*(j-b[i]);
                if(d[p]>d[s]+a[b[i]][j])d[p]=d[s]+a[b[i]][j],q.push(que(p,d[p]));
            }
        }
    }
    printf("%d",d[e]);
    return 0;
}
