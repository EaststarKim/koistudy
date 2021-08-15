#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int s,t,i;
    bool operator<(const data&r)const{
        if(s==r.s){
            if(t==r.t)return i<r.i;
            return t>r.t;
        }
        return s>r.s;
    }
}a[2010];
int chk[2010][2010],s[2010];
int main(){
    int i,j,n,t,p;
    scanf("%d%d%d",&n,&t,&p);
    for(i=1;i<=n;++i){
        for(j=1;j<=t;++j)scanf("%d",chk[i]+j),s[j]+=!chk[i][j];
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=t;++j)a[i].s+=chk[i][j]*s[j],a[i].t+=chk[i][j];
        a[i].i=i;
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;++i)if(a[i].i==p)break;
    printf("%d %d",a[i].s,i);
    return 0;
}
