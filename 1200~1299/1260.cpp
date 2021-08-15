#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int a,b;
    bool operator<(const data&r)const{
        if(a*r.b==r.a*b)return a>r.a;
        return a*r.b>r.a*b;
    }
}a[200010];
int main(){
    int i,n,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].a,&a[i].b);
    sort(a+1,a+n+1);
    for(i=1;i<=n;++i)ans=(ans+a[i].a*ans+a[i].b)%40000;
    printf("%d",ans);
    return 0;
}
