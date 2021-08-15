#include <stdio.h>
#include <string.h>

char a[51];

int main()
{
	int i, j, n, l, r, h;
	char c;
	fgets(a,50,stdin);
	n=strlen(a);
	a[n-1]=' ';
	l=0;
	for(i=0;i<n;++i)
	{
		if(a[i]==' ' || a[i]=='.' || a[i]=='!')
		{
			r=i-1;
			h=(l+r)/2;
			for(j=l;j<=h;++j) 
			{
				c=a[j];
				a[j]=a[l+r-j];
				a[l+r-j]=c;
			}
			l=i+1;
		}
	}
	--n;
	for(i=0;i<n;++i)
	{
		if(a[i]>=97) printf("%c",a[i]+'A'-'a');
		else printf("%c",a[i]);
	}
	return 0;
}