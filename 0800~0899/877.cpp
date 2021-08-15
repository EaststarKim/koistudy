#include <stdio.h>
struct data{
    int s,r;
}tree[1<<18];
int i,s,e,c;
void update(int n,int si,int ei){
    if(ei<s||e<si)return;
    if(s<=si&&ei<=e){
        tree[n].s=c;
        tree[n].r=i;
        return;
    }
    int m=(si+ei)/2,l=n*2,r=l+1;
    update(l,si,m);
    update(r,m+1,ei);
}
void init(int n,int si,int ei){
    if(si==ei){
        printf("%d ",tree[n].s);
        return;
    }
    int m=(si+ei)/2,l=n*2,r=l+1;
    if(tree[n].r>tree[l].r)tree[l]=tree[n];
    if(tree[n].r>tree[r].r)tree[r]=tree[n];
    init(l,si,m);
    init(r,m+1,ei);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i){
        scanf("%d%d%d",&s,&e,&c);
        update(1,1,n);
    }
    init(1,1,n);
    return 0;
}
