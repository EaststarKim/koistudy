#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
struct data{
    int r,c;
    bool operator<(const data&p)const{
        return r<p.r;
    }
}b[100010];
int a[100010],ans=-1;
priority_queue<int,vector<int>,greater<int> > q;
int main(){
    int i,j,n,m,s,l,r,mid;
    long long t;
    scanf("%d%d%d",&n,&m,&s);
    for(i=1;i<=m;++i)scanf("%d",a+i);
    for(i=1;i<=n;++i)scanf("%d",&b[i].r);
    for(i=1;i<=n;++i)scanf("%d",&b[i].c);
    sort(a+1,a+m+1);
    sort(b+1,b+n+1);
    l=(m+n-1)/n,r=m;
    while(l<=r){
        mid=(l+r)/2;
        t=0;
        priority_queue<int,vector<int>,greater<int> > empty;
        swap(q,empty);
        for(i=m,j=n;i>0;i-=mid){
            for(;b[j].r>=a[i];--j)q.push(b[j].c);
            if(q.empty())break;
            t+=q.top(),q.pop();
            if(t>s)break;
        }
        if(i>0)l=mid+1;
        else ans=mid,r=mid-1;
    }
    printf("%d",ans);
}
