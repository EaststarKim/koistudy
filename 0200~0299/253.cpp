#include <stdio.h>
#include <algorithm>
struct data

{
	bool st;
	int x;
	bool operator < (const data& p) const
	{
		return x < p.x;
	}
}a[10005];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a[2*i].x,&a[2*i+1].x);
		a[2*i].st = 1; a[2*i+1].st = 0;
	}
	std::sort(a,a+2*n);
	int cnt=0,answer1=0,answer2=0,start=a[0].x,tmp;
	for(i=0;i<2*n;i++)
	{
		if(cnt==0 && a[i].x != a[i-1].x)
		{
			tmp = a[i].x - start;
			start = a[i].x;
			if(answer2 < tmp) answer2 = tmp;
		}
		if(a[i].st ==1) cnt++;
		else cnt--;
		if(cnt==0 && a[i].x != a[i+1].x)
		{
			tmp = a[i].x - start;
			start = a[i].x;
			if(answer1 < tmp) answer1 = tmp;
		}
	}
	printf("%d %d",answer1,answer2);
	return 0;
}

