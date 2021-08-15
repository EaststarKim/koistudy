#include <bits/stdc++.h>
using namespace std;
long long a[1010],s,ans=-1e9;
int main(){
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%lld",a+i),ans=max(ans,a[i]);
	for(i=1;i<=n;i+=2)if(a[i]>0)s+=a[i];
	ans=max(ans,s);
	for(s=0,i=2;i<=n;i+=2)if(a[i]>0)s+=a[i];
	ans=max(ans,s);
	printf("%lld",ans);
	return 0;
}
