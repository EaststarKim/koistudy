#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int a,i;
    bool operator<(const data&r)const{
        if(a==r.a)return i>r.i;
        return a<r.a;
    }
}b[70010];
int a[70010],D[70010],t[1<<19],ans;
void update(int n,int s,int e,int p,int k){
    if(e<p||p<s)return;
    if(s==e){
        t[n]=k;
        return;
    }
    int m=(s+e)/2,l=n*2,r=l+1;
    update(l,s,m,p,k),update(r,m+1,e,p,k);
    t[n]=max(t[l],t[r]);
}
int query(int n,int s,int e,int p){
    if(p<s)return 0;
    if(e<=p)return t[n];
    int m=(s+e)/2,l=n*2,r=l+1;
    return max(query(l,s,m,p),query(r,m+1,e,p));
}
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i),b[i]={a[i],i};
    sort(b+1,b+n+1);
    for(i=1;i<=n;++i){
        D[i]=query(1,1,n,b[i].i-2)+1;
        ans=max(ans,D[i]);
        update(1,1,n,b[i].i,D[i]);
    }
    printf("%d",ans);
    return 0;
}
