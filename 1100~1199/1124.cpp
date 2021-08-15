#include <stdio.h>
int cnt[1000010],a[1000010],s;
void f(int s,int e){++a[s],--a[e+1];}
int main(){
    int i,n,t,k;
    scanf("%d%d",&n,&t);
    for(i=1;i<=t;++i){
        scanf("%d",&k);
        ++cnt[k];
        if(cnt[k]*2+1>n){
            if(cnt[k]>=n)f(1,n);
            else f(1,k-1),f(k+1,n);
        }
        else{
            if(cnt[k]>=k)f(1,k-1),f(n+k-cnt[k],n);
            else f(k-cnt[k],k-1);
            if(k+cnt[k]>n)f(k+1,n),f(1,k+cnt[k]-n);
            else f(k+1,k+cnt[k]);
        }
    }
    for(i=1;i<=n;++i){
        s+=a[i];
        printf("%d\n",s);
    }
    return 0;
}
