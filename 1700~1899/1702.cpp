#include <stdio.h>
#include <algorithm>
using namespace std;
int t[1<<19];
void init(int n,int s,int e){
    if(s==e){
        scanf("%d",t+n);
        return;
    }
    int l=n*2,r=l+1,m=(s+e)/2;
    init(l,s,m);
    init(r,m+1,e);
    t[n]=min(t[l],t[r]);
}
int query(int n,int s,int e,int si,int ei){
    if(ei<s||e<si)return 1e9;
    if(si<=s&&e<=ei)return t[n];
    int l=n*2,r=l+1,m=(s+e)/2;
    return min(query(l,s,m,si,ei),query(r,m+1,e,si,ei));
}
int main(){
    int n,m,s,e;
    scanf("%d%d",&n,&m);
    init(1,1,n);
    for(;m--;){
        scanf("%d%d",&s,&e);
        printf("%d\n",query(1,1,n,s,e));
    }
    return 0;
}
