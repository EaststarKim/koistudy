#include <stdio.h>
#define M(k) (k-1+n)%n
int a[8],t[8],ans[8],n,mx;
void f(int p,int s){
    int i;
    if(p==n){
        if(s>mx){
            mx=s;
            for(i=0;i<n;++i)ans[i]=t[i];
        }
        return;
    }
    for(t[p]=0;a[p]>=0&&a[M(p)]>=0;--a[p],a[M(p)]-=++t[p])f(p+1,s+t[p]);
    a[p]+=t[p];
    a[M(p)]+=t[p]*(t[p]+1)/2;
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%d",a+i);
    f(0,0);
    printf("%d\n",mx);
    for(i=0;i<n;++i)printf("%d ",ans[i]);
    return 0;
}
