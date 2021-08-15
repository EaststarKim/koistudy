#include <stdio.h>
#include <algorithm>
using namespace std;
int a[2010],n;
long long D[2010][2010],mx;
int m(int k){return (k+n)%n;}
long long f(int l,int r,int t){
    if(t>=n)return 0;
    if(D[l][r])return D[l][r];
    if(t%2==1){
        if(a[l]<a[r])return D[l][r]=f(l,m(r+1),t+1);
        return D[l][r]=f(m(l-1),r,t+1);
    }
    return D[l][r]=max(a[l]+f(m(l-1),r,t+1),a[r]+f(l,m(r+1),t+1));
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%lld",a+i);
    for(i=0;i<n;++i)mx=max(mx,a[i]+f(m(i-1),m(i+1),1));
    printf("%lld",mx);
    return 0;
}
