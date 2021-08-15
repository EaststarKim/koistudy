#include <stdio.h>
#include <algorithm>
using namespace std;
struct adj_list{int e,nx;}al[400010];
int a[200010],b[200010],st[200010],n,t;
int lev[200010],p[200010][18];
void make_al(int s,int e){al[++t]={e,st[s]},st[s]=t;}
struct Node{
    int cnt;
    Node *l,*r;
    Node(int cnt,Node *l,Node *r):cnt(cnt),l(l),r(r){}
    Node *update(int s,int e,int k);
}*root[200010];
Node *null=new Node(0,NULL,NULL);
Node *Node::update(int s,int e,int k){
    if(e<k||k<s)return this;
    if(s==e)return new Node(this->cnt+1,null,null);
    int m=(s+e)/2;
    return new Node(this->cnt+1,this->l->update(s,m,k),this->r->update(m+1,e,k));
}
int query(Node *a,Node *b,Node *c,Node *d,int s,int e,int k){
    if(s==e)return s;
    int m=(s+e)/2,cnt=a->r->cnt+b->r->cnt-c->r->cnt-d->r->cnt;
    if(cnt<k)return query(a->l,b->l,c->l,d->l,s,m,k-cnt);
    return query(a->r,b->r,c->r,d->r,m+1,e,k);
}
void dfs(int s){
    int i;
    for(i=1;i<18;++i)p[s][i]=p[p[s][i-1]][i-1];
    for(i=st[s];i;i=al[i].nx)if(!lev[al[i].e]){
        lev[al[i].e]=lev[s]+1;
        root[al[i].e]=root[s]->update(1,n,a[al[i].e]);
        p[al[i].e][0]=s;
        dfs(al[i].e);
    }
}
int find_lca(int x,int y){
    if(lev[x]>lev[y])swap(x,y);
    int i,gap=lev[y]-lev[x];
    for(i=0;i<18;++i)if(gap&(1<<i))y=p[y][i];
    if(x==y)return x;
    for(i=18;i--;)if(p[x][i]!=p[y][i])x=p[x][i],y=p[y][i];
    return p[x][0];
}
int main(){
    int i,q,s,e,k,lca,kth;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;++i)scanf("%d",a+i),b[i]=a[i];
    sort(b+1,b+n+1);
    for(i=1;i<=n;++i)a[i]=(lower_bound(b+1,b+n+1,a[i])-b);
    for(i=1;i<n;++i){
        scanf("%d%d",&s,&e);
        make_al(s,e);make_al(e,s);
    }
    lev[1]=1;
    root[0]=null->l=null->r=null;
    root[1]=null->update(1,n,a[1]);
    dfs(1);
    for(;q--;){
        scanf("%d%d%d",&s,&e,&k);
        lca=find_lca(s,e);
        if(lev[s]+lev[e]-lev[lca]*2+1<k||k<1)puts("-1");
        else{
            kth=query(root[s],root[e],root[lca],root[p[lca][0]],1,n,k);
            printf("%d\n",b[kth]);
        }
    }
    return 0;
}
