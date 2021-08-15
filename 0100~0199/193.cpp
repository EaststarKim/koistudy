#include <stdio.h>
#include <string.h>
char a[20];
int main()
{
	int i,j,n,f,r;
	scanf("%d",&n);
	scanf("%s",a);
	f=0;
	r=n-1;
	for(i=0;i<n;++i)
	{
		if(a[f]<a[r])
		{
			printf("%c",a[f]);
			++f;
			continue;
		}
		if(a[f]==a[r])
		{
			for(j=f;j<=(f+r)/2;++j)
			{
				if(a[j]>a[f+r-j])
				{
					printf("%c",a[r]);
					--r;
					break;
				}
				if(a[j]<a[f+r-j])
				{
					printf("%c",a[f]);
					++f;
					break;
				}
			}
			if(j>(f+r)/2)
			{
				printf("%c",a[f]);
				++f;
			}
		}
		else
		{
			printf("%c",a[r]);
			--r;
		}
	}
	return 0;
}