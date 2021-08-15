#include <stdio.h>
#include <algorithm>
using namespace std;
int a[10010],b[10010],s;
long long ans;
int main(){
    int i,j,n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=m;++i)scanf("%d",b+i);
    for(i=j=1;;){
        i+=!a[i],j+=!b[j];
        if(i>n||j>m)break;
        k=min(a[i],b[j]);
        a[i]-=k,b[j]-=k,s+=k,ans+=(i+j)*k;
    }
    printf("%d %lld",s,ans);
    return 0;
}
