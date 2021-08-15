#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int a,b;
    bool operator<(const data&r)const{
        return a<r.a;
    }
}a[100010];
int chk[100010],ans;
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].a,&a[i].b);
    sort(a+1,a+n+1);
    int mx=a[1].b;
    for(i=2;i<=n;++i){
        if(a[i].a==a[i-1].a)chk[i]=1;
        if(mx>=a[i].b)chk[i]=1;
        mx=max(mx,a[i].b);
    }
    int mn=a[n].b;
    for(i=n-1;i;--i){
        if(a[i].a==a[i+1].a)chk[i]=1;
        if(mn<=a[i].b)chk[i]=1;
        mn=min(mn,a[i].b);
    }
    for(i=1;i<=n;++i)ans+=!chk[i];
    printf("%d",ans);
    return 0;
}
