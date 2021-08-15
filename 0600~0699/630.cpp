#include <stdio.h>
#include <algorithm>
struct data{
	int p,s;
	bool operator<(const data&r)const{
		return p+s<r.p+r.s;
	}
}a[1010];
int d[101010],mx;
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",&a[i].p,&a[i].s);
	std::sort(&a[1],&a[n+1]);
	d[0]=1;
	for(i=1;i<=n;++i){
		for(j=a[i].p;j>=0;--j){
			if(d[j]){
				d[j+a[i].s]=1;
				if(mx<j+a[i].s)mx=j+a[i].s;
			}
		}
	}
	printf("%d",mx);
	return 0;
}
