#include <bits/stdc++.h>
using namespace std;
int a[2010];
int main(){
	int i,j,n,k;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(i=1;i<n;++i)a[n+i]=a[i]+1e6;
	scanf("%d",&k);
	int l=0,r=1e6,m,ans;
	while(l<=r){
		m=(l+r)/2;
		for(i=1;i<=n;++i){
			int s,cnt=1;
			for(s=j=0;j<n;++j)if(a[i+j]-a[i+s]>m*2)s=j,++cnt;
			if(cnt<=k)break;
		}
		if(i>n)l=m+1;
		else r=m-1,ans=m;
	}
	printf("%d",ans);
	return 0;
}
