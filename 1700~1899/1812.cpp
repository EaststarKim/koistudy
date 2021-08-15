#include <bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i),b[i]=a[i];
    sort(b+1,b+n+1);
    for(i=j=1;i<=n;++i)if(b[i]!=b[i-1])b[j++]=b[i];
    for(i=1;i<=n;++i)printf("%d ",lower_bound(b+1,b+j,a[i])-b);
    return 0;
}
