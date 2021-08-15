#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
struct data{
    int w,s,i;
    bool operator<(const data&r)const{
        return s>r.s;
    }
}t[1000010];
bool cmp(data a,data b){return a.w>b.w;}
int a[50010],b[50010];
int chk[1000010];
int main(){
    int i,A,B,T,w,s;
    scanf("%d%d%d",&A,&B,&T);
    for(i=1;i<=A;++i)scanf("%d",a+i);
    for(i=1;i<=B;++i)scanf("%d",b+i);
    sort(a+1,a+A+1);
    sort(b+1,b+B+1);
    for(i=1;i<=T;++i){
        scanf("%d%d",&w,&s);
        w=upper_bound(a+1,a+A+1,w)-a;
        s=upper_bound(b+1,b+B+1,s)-b;
        t[i]={w,s,i};
        if(w>A&&s>B){
            puts("-1");
            return 0;
        }
    }
    t[0]={A+1,B+1,0};
    int l=1,r=T,m,ans;
    long long sum;
    while(l<=r){
        m=(l+r)/2;
        sum=0;
        sort(t+1,t+T+1,cmp);
        priority_queue<data> q;
        for(i=1;i<=T;++i)chk[i]=0;
        for(i=1;i<=T;++i){
            if(t[i-1].w>t[i].w)sum+=(long long)(t[i-1].w-t[i].w)*m;
            if(t[i].w>A)continue;
            --sum;
            chk[t[i].i]=1;
            q.push(t[i]);
            if(sum<0){
                data tmp=q.top();
                q.pop();
                ++sum;
                chk[tmp.i]=0;
            }
        }
        sum=0;
        sort(t+1,t+T+1);
        for(i=1;i<=T;++i){
            if(t[i-1].s>t[i].s)sum+=(long long)(t[i-1].s-t[i].s)*m;
            if(chk[t[i].i])continue;
            if(t[i].s>B)break;
            --sum;
            if(sum<0)break;
        }
        if(i>T)r=m-1,ans=m;
        else l=m+1;
    }
    printf("%d",ans);
    return 0;
}
