#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100010];
int main(){
    int i,n,s,t;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    sort(a+1,a+n+1);
    s=t=a[n];
    for(i=n-1;i;--i)t=t<a[i]?2:t-a[i]+1;
    printf("%d",(n+s)/2-(t-1)/2);
    return 0;
}
