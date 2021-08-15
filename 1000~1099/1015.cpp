#include <stdio.h>
#include <algorithm>
#define SZ 300010
using namespace std;
struct data{
    int i,s;
    bool operator<(const data&r)const{
        return s<r.s;
    }
}a[SZ];
struct tree{
    int l;
    long long cnt;
}b[SZ],t[SZ*4];
int idx[SZ],ans[SZ],m,k,mx,flag,an;
void update(int n,int si,int ei,int i){
    if(i<si||ei<i)return;
    if(si==ei){
        t[n]=b[i];
        return;
    }
    int m=(si+ei)/2,l=n*2,r=l+1;
    long long cnt=0;
    update(l,si,m,i);
    update(r,m+1,ei,i);
    t[n].l=max(t[l].l,t[r].l);
    if(t[n].l==t[l].l)cnt+=t[l].cnt;
    if(t[n].l==t[r].l)cnt+=t[r].cnt;
    t[n].cnt=cnt>k?k:cnt;
}
tree query(int n,int si,int ei,int s,int e){
    if(ei<s||e<si)return t[0];
    if(s<=si&&ei<=e)return t[n];
    int m=(si+ei)/2,l=n*2,r=l+1;
    long long cnt=0;
    tree tn,tl=query(l,si,m,s,e),tr=query(r,m+1,ei,s,e);
    tn.l=max(tl.l,tr.l);
    if(tn.l==tl.l)cnt+=tl.cnt;
    if(tn.l==tr.l)cnt+=tr.cnt;
    tn.cnt=cnt>k?k:cnt;
    return tn;
}
void back(int p,int s){
    int i;
    if(an==mx){
        flag=1;
        return;
    }
    for(i=p+1;i<=m;++i)if(a[p].i<a[i].i&&b[p].l==b[i].l+1){
        if(b[i].cnt+s<k)s+=b[i].cnt;
        else{
            ans[++an]=a[i].s;
            back(i,s);
            break;
        }
    }
}
int main(){
    int i,j;
    scanf("%d%d",&m,&k);
    for(i=1;i<=m;++i)scanf("%d",&a[i].s),a[i].i=i;
    sort(a+1,a+m+1);
    for(i=1;i<=m;++i)idx[a[i].i]=i;
    b[idx[m]].l=b[idx[m]].cnt=1;
    update(1,1,m,idx[m]);
    for(i=m-1;i>0;--i){
        j=idx[i];
        b[j]=query(1,1,m,j+1,m);
        ++b[j].l;
        if(!b[j].cnt)b[j].cnt=1;
        update(1,1,m,j);
        mx=max(mx,b[j].l);
    }
    b[0].l=mx+1;
    back(0,0);
    if(flag){
        printf("%d\n",mx);
        for(i=1;i<=mx;++i)printf("%d ",ans[i]);
    }
    else puts("-1");
    return 0;
}
