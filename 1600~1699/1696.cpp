#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int cnt,lazy;
    data *l,*r;
    data(){cnt=lazy=0,l=r=nullptr;}
}*root;
const int H=29;
void lp(int x,data *p){
    if(p->lazy&x)swap(p->l,p->r);
    if(p->l)p->l->lazy^=p->lazy;
    if(p->r)p->r->lazy^=p->lazy;
    p->lazy=0;
}
void add(int n,data *p,int k){
    int x=1<<n;
    if(n<0){
        p->cnt=1;
        return;
    }
    if(p->lazy)lp(x,p);
    if(k&x){
        if(p->r==nullptr)p->r=new data();
        add(n-1,p->r,k);
    }
    else{
        if(p->l==nullptr)p->l=new data();
        add(n-1,p->l,k);
    }
    p->cnt=(p->r?p->r->cnt:0)+(p->l?p->l->cnt:0);
}
int mx(int n,data *p,int k,int s){
    int x=1<<n;
    if(n<0)return k^s;
    if(p->lazy)lp(x,p);
    if(k&x){
        if(p->l)return mx(n-1,p->l,k,s);
        else return mx(n-1,p->r,k,s+x);
    }
    else{
        if(p->r)return mx(n-1,p->r,k,s+x);
        else return mx(n-1,p->l,k,s);
    }
}
int s(int n,data *p,int k){
    int x=1<<n;
    if(n<0)return p->cnt;
    if(p->lazy)lp(x,p);
    if(k&x)return (p->l?p->l->cnt:0)+(p->r?s(n-1,p->r,k):0);
    else return (p->l?s(n-1,p->l,k):0);
}
int main(){
    int i,q,t,x,y;
    scanf("%d",&q);
    root=new data();
    add(H,root,0);
    for(;q--;){
        scanf("%d%d",&t,&x);
        if(t==1)add(H,root,x);
        if(t==2)root->lazy^=x;
        if(t==3)printf("%d\n",mx(H,root,x,0));
        if(t==4){
            scanf("%d",&y);
            printf("%d\n",s(H,root,y)-s(H,root,x-1));
        }
    }
    return 0;
}
