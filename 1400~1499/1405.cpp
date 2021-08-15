#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
	int x,y;
	bool operator<(const data&r)const{
		return y<r.y;
	}
}a[100010];
int cnt;
int main(){
	int i,n,k=1;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y),a[i].y+=a[i].x;
	sort(a+1,a+n+1);
	for(i=2;i<=n;++i)if(a[k].y<a[i].x)k=i,++cnt;
	printf("%d",++cnt);
	return 0;
}
