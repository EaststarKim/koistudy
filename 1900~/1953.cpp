#include <stdio.h>
#include <algorithm>
using namespace std;
struct Node{
    int s;
    Node *l,*r;
    Node(int s,Node *l,Node *r):s(s),l(l),r(r){}
    Node *update(int s,int e,int k);
}*root[100010];
Node *null=new Node(0,NULL,NULL);
Node *Node::update(int s,int e,int k){
    if(e<k||k<s)return this;
    if(s==e)return new Node(1,null,null);
    int m=(s+e)/2;
    return new Node(this->s+1,this->l->update(s,m,k),this->r->update(m+1,e,k));
}
int query(Node *a,Node *b,int s,int e,int k){
    if(s==e)return s;
    int m=(s+e)/2;
    if((b->l->s)-(a->l->s)<k)return query(a->r,b->r,m+1,e,k-(b->l->s)+(a->l->s));
    return query(a->l,b->l,s,m,k);
}
int a[100010],b[100010];
int main(){
    int i,n,m,s,e,k;
    scanf("%d%d",&n,&m);
    root[0]=null->l=null->r=null;
    for(i=1;i<=n;++i)scanf("%d",a+i),b[i]=a[i];
    sort(b+1,b+n+1);
    for(i=1;i<=n;++i)a[i]=lower_bound(b+1,b+n+1,a[i])-b;
    for(i=1;i<=n;++i)root[i]=root[i-1]->update(1,n,a[i]);
    for(;m--;){
        scanf("%d%d%d",&s,&e,&k);
        printf("%d\n",b[query(root[s-1],root[e],1,n,k)]);
    }
    return 0;
}
