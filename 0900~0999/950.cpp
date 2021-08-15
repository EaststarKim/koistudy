#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct tree{
    int p,s,e;
    tree(){}tree(int p,int s,int e):p(p),s(s),e(e){}
}t[1<<22];
char c[1000010];
void init(int n,int s,int e){
    if(s==e){
        if(c[s]=='(')t[n].s=1;
        else t[n].e=1;
        return;
    }
    int m=(s+e)/2,l=n*2,r=l+1,p;
    init(l,s,m);
    init(r,m+1,e);
    p=min(t[l].s,t[r].e);
    t[n].p=t[l].p+t[r].p+p;
    t[n].s=t[l].s+t[r].s-p;
    t[n].e=t[l].e+t[r].e-p;
}
tree query(int n,int s,int e,int si,int ei){
    if(e<si||ei<s)return tree(0,0,0);
    if(si<=s&&e<=ei)return t[n];
    int m=(s+e)/2,l=n*2,r=l+1,p;
    tree lt=query(l,s,m,si,ei),rt=query(r,m+1,e,si,ei);
    p=min(lt.s,rt.e);
    return tree(lt.p+rt.p+p,lt.s+rt.s-p,lt.e+rt.e-p);
}
int main(){
    int n,m,s,e;
    scanf("%s\n%d",c+1,&m);
    n=strlen(c+1);
    init(1,1,n);
    for(;m--;){
        scanf("%d%d",&s,&e);
        printf("%d\n",query(1,1,n,s,e).p*2);
    }
    return 0;
}
