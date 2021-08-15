#include <bits/stdc++.h>
using namespace std;
vector<int> a[10010];
int q[10010],d[10010],f,r=1;
int main(){
	int i,n,m,k,mn=1e9;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&m);
		for(;m--;)scanf("%d",&k),a[i].push_back(k);
		d[i]=1e9;
	}
	q[1]=d[1]=1;
	while(f<r){
		i=q[++f];
		for(auto j:a[i])if(d[i]<d[j])q[++r]=j,d[j]=d[i]+1;
	}
	for(i=1;i<=n;++i)if(d[i]>n)break;
	puts(i>n?"Y":"N");
	for(i=1;i<=n;++i)if(!a[i].size())mn=min(mn,d[i]);
	printf("%d",mn);
	return 0;
}
