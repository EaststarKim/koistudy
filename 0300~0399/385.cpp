#include <stdio.h>
#include <algorithm>
#include <set>
#include <functional>
using namespace std;
pair<int,int> a[100010];
set<int,greater<int> > S;
int main(){
	int i,n,t;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",&a[i].first,&a[i].second);
	sort(a+1,a+n+1);
	for(i=1;i<=n;++i){
		t=a[i].second;
		typeof(S.begin())it=S.upper_bound(t);
		if(it!=S.end())S.erase(it);
		S.insert(t);
	}
	printf("%d",S.size());
	return 0;
}
