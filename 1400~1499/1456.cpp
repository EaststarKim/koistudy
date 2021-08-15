#include <stdio.h>
#include <algorithm>
using namespace std;
int t[1<<23][4];
void init(int n,int s,int e){
    if(s==e){
        t[n][1]=1e9;
        return;
    }
    int l=n*2,r=l+1,m=(s+e)/2;
    init(l,s,m);
    init(r,m+1,e);
    t[n][1]=1e9;
}
void lazy(int n,int op,int h,int ts){
    if(!ts)return;
    if(op<2){
        if(t[n][0]<h)t[n][0]=h,t[n][2]=ts;
        if(t[n][1]<h)t[n][1]=h,t[n][3]=ts;
    }
    else{
        if(t[n][1]>h)t[n][1]=h,t[n][3]=ts;
        if(t[n][0]>h)t[n][0]=h,t[n][2]=ts;
    }
}
void update(int n,int s,int e,int si,int ei,int op,int h,int ts){
    if(ei<s||e<si)return;
    if(si<=s&&e<=ei){
        lazy(n,op,h,ts);
        return;
    }
    int l=n*2,r=l+1,m=(s+e)/2;
    if(t[n][2]<t[n][3]){
        lazy(l,1,t[n][0],t[n][2]),lazy(r,1,t[n][0],t[n][2]);
        lazy(l,2,t[n][1],t[n][3]),lazy(r,2,t[n][1],t[n][3]);
    }
    else{
        lazy(l,2,t[n][1],t[n][3]),lazy(r,2,t[n][1],t[n][3]);
        lazy(l,1,t[n][0],t[n][2]),lazy(r,1,t[n][0],t[n][2]);
    }
    t[n][0]=t[n][2]=t[n][3]=0,t[n][1]=1e9;
    update(l,s,m,si,ei,op,h,ts);
    update(r,m+1,e,si,ei,op,h,ts);
}
void fin(int n,int s,int e){
    if(s==e){
        printf("%d ",t[n][0]);
        return;
    }
    int l=n*2,r=l+1,m=(s+e)/2;
    if(t[n][2]<t[n][3]){
        lazy(l,1,t[n][0],t[n][2]),lazy(r,1,t[n][0],t[n][2]);
        lazy(l,2,t[n][1],t[n][3]),lazy(r,2,t[n][1],t[n][3]);
    }
    else{
        lazy(l,2,t[n][1],t[n][3]),lazy(r,2,t[n][1],t[n][3]);
        lazy(l,1,t[n][0],t[n][2]),lazy(r,1,t[n][0],t[n][2]);
    }
    t[n][0]=t[n][2]=t[n][3]=0,t[n][1]=1e9;
    fin(l,s,m);
    fin(r,m+1,e);
}
int main(){
    int i,n,k,op,s,e,h;
    scanf("%d%d",&n,&k);
    init(1,1,n);
    for(i=1;i<=k;++i){
        scanf("%d%d%d%d",&op,&s,&e,&h);
        update(1,1,n,s+1,e+1,op,h,i);
    }
    fin(1,1,n);
    return 0;
}
