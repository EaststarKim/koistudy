#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
	int w,s;
	bool operator<(const data&r)const{
        return s>r.s;
	}
}a[50010];
int b[50010],m=-1e6;
int main(){
    int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",&a[i].w,&a[i].s),a[i].s+=a[i].w;
	sort(a+1,a+n+1);
	for(i=n;i;--i)b[i]=b[i+1]+a[i].w;
	for(i=1;i<=n;++i)m=max(m,b[i]-a[i].s);
	printf("%d",m);
	return 0;
}
