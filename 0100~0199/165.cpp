#include <iostream>
#include <algorithm>
using namespace std;

struct G
{
	int x, y;
	bool operator()(G a, G b)
	{
		return a.y<b.y;
	}
}b[5];

int a[5][6];

int main()
{
	int i, j, t;
	for(i=1;i<=4;++i)
	{
		for(j=1;j<=5;++j)cin>>a[i][j];
	}
	for(i=1;i<=4;++i)b[i].x=i,b[i].y=3*a[i][1]+a[i][2];
	sort(&b[1],&b[5],G());
	for(i=1;i<=4;++i)
	{
		for(j=i;j<=4;++j)
		{
			if(b[i].y==b[j].y)
			{
				if(a[b[i].x][4]>a[b[j].x][4])t=b[i].x,b[i].x=b[j].x,b[j].x=t;
				if(a[b[i].x][4]==a[b[j].x][4])
				{
					if(a[b[i].x][5]>a[b[j].x][5])t=b[i].x,b[i].x=b[j].x,b[j].x=t;
				}
			}
		}
	}
	cout<<b[4].x<<endl<<b[3].x;
	return 0;
}