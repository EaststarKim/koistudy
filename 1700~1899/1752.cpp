#include <bits/stdc++.h>
using namespace std;
struct data{
    int d,t;
    bool operator<(const data&r)const{
        return t>r.t;
    }
}a[1000010];
int main(){
    int i,n,t=1e9;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].d,&a[i].t);
    sort(a+1,a+n+1);
    for(i=1;i<=n;++i)t=min(t,a[i].t)-a[i].d;
    printf("%d",t);
    return 0;
}
