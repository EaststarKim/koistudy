#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct data{
    int x,sy,ey,t;
    data(){}
    data(int x,int sy,int ey,int t):x(x),sy(sy),ey(ey),t(t){}
    bool operator<(const data&r)const{
        return x<r.x;
    }
}a[21];
struct segment{
    int chk,sum;
}tree[1<<17];
void update(int n,int s,int e,int si,int ei,int t){
    if(ei<s||e<si)return;
    int m=(s+e)/2,l=n*2,r=l+1;
    if(si<=s&&e<=ei)tree[n].chk+=t;
    else{
        update(l,s,m,si,ei,t);
        update(r,m+1,e,si,ei,t);
    }
    tree[n].sum=0;
    if(!tree[n].chk)tree[n].sum=tree[l].sum+tree[r].sum;
    else if(tree[n].chk&&s<=e)tree[n].sum=e-s+1;
}
int main(){
    int i,n,x,y,z,w,ans=0;
    scanf("%d",&n);
    n*=2;
    for(i=1;i<=n;i+=2){
        scanf("%d%d%d%d",&x,&y,&z,&w);
        a[i]=data(x,w+1e4,y+1e4,1);
        a[i+1]=data(z,w+1e4,y+1e4,-1);
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;++i){
        ans+=tree[1].sum*(a[i].x-a[i-1].x);
        update(1,0,20000,a[i].sy,a[i].ey-1,a[i].t);
    }
    printf("%d",ans);
    return 0;
}
