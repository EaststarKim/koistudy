#include <bits/stdc++.h>
using namespace std;
int a[200010],b[200010],ans;
int main(){
    int i,j,n,s;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i<=n;++i)scanf("%d",b+i);
    for(i=1<<29;i;i/=2){
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        for(s=0,j=1;j<=n;++j)s^=n-(lower_bound(b+1,b+n+1,i-a[j])-b-1)-(lower_bound(b+1,b+n+1,i*3-a[j])-lower_bound(b+1,b+n+1,i*2-a[j]));
        if(s&1)ans+=i;
        for(j=1;j<=n;++j)a[j]-=a[j]&i,b[j]-=b[j]&i;
    }
    printf("%d",ans);
    return 0;
}
