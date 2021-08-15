#include <bits/stdc++.h>
using namespace std;
int a[100010],ans;
int main(){
	int i,n,k;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=n;--i;)a[i+1]-=a[i];
	sort(a+2,a+n+1);
	for(i=1;i++<=n-k;)ans+=a[i];
	printf("%d",ans+k);
	return 0;
}
