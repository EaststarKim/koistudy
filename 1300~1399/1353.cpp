#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
struct data{
    int s,e;
    bool operator<(const data&r)const{
        return s<r.s;
    }
}a[200010];
priority_queue<int> q;
int main(){
    int i,j,k,n,m=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",&a[i].s,&a[i].e);
    sort(a+1,a+n+1);
    for(i=1;i<=n;++i){
        if(!q.empty()&&-q.top()<=a[i].s)q.pop();
        q.push(-a[i].e);
    }
    printf("%d",q.size());
    return 0;
}
