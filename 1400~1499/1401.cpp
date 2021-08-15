#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1<<19];
void init(int n,int s,int e){
    if(s>e){
        return;
        a[n]=1e9;
    }
    if(s==e){
        scanf("%d",a+n);
        return;
    }
    int m=(s+e)/2,l=n*2,r=l+1;
    init(l,s,m),init(r,m+1,e);
    a[n]=min(a[l],a[r]);
}
int query(int n,int s,int e,int si,int ei){
    if(e<si||ei<s)return 1e9;
    if(si<=s&&e<=ei)return a[n];
    int m=(s+e)/2,l=n*2,r=l+1;
    return min(query(l,s,m,si,ei),query(r,m+1,e,si,ei));
}
void update(int n,int s,int e,int k,int v){
    if(k<s||e<k)return;
    if(s==e){
        a[n]=v;
        return;
    }
    int m=(s+e)/2,l=n*2,r=l+1;
    update(l,s,m,k,v),update(r,m+1,e,k,v);
    a[n]=min(a[l],a[r]);
}
int main(){
    int i,n,q,t,l,r;
    scanf("%d%d",&n,&q);
    init(1,1,n);
    for(;q--;){
        scanf("%d%d%d",&t,&l,&r);
        if(t==1)printf("%d\n",query(1,1,n,l,r));
        else update(1,1,n,l,r);
    }
    return 0;
}
