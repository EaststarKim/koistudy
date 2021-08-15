#include <stdio.h>
#include <algorithm>
struct data{
	int x,y;
	bool operator<(const data&r)const{
        return x<r.x;
    }
}a[100010];
int x[100010],s;
int main()
{
    int i,j=0,m,n,l;
	scanf("%d%d%d",&m,&n,&l);
	for(i=0;i<m;i++)scanf("%d",&x[i]);
	for(i=0;i<n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	std::sort(x,x+m);
	std::sort(a,a+n);
	for(i=0;i<n;++i){
		for(;j<m&&x[j]<a[i].x;++j);
		if((j>0&&a[i].x-x[j-1]+a[i].y<=l)||(j<m&&x[j]-a[i].x+a[i].y<=l))++s;
	}
	printf("%d",s);
	return 0;
}
