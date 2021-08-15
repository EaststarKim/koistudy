#include <stdio.h>
#define M 9999991
long long ans=1;
int inv[510];
int a[510],t[510],s[510],l[510],r[510],cnt=1;
void f(int p){
    ++s[p];
    if(!t[p]){
        t[p]=a[cnt++];
        return;
    }
    if(t[p]>a[cnt])f(l[p]?l[p]:l[p]=cnt);
    else f(r[p]?r[p]:r[p]=cnt);
}
void sol(int p){
    if(!t[p])return;
    ans=ans*inv[s[p]]%M;
    sol(l[p]);
    sol(r[p]);
}
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=n;++i)ans=ans*i%M;
    inv[1]=1;
    for(i=2;i<=n;++i)inv[i]=(long long)(M-M/i)*inv[M%i]%M;
    for(i=1;i<=n;++i)f(1);
    sol(1);
    printf("%lld",ans);
    return 0;
}
