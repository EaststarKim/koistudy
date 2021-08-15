#include <cstdio>
#include <cstring>
int a[40]={1},r;
char c[40],s[40];
int main()
{
	int i,n;
	scanf("%s",c);
	n=strlen(c);
	for(i=0;i<n;++i)
	{
		if(c[i]=='('||c[i]=='[')
		{
			s[++r]=c[i];
		}
		if(c[i]==')')
		{
			if(!r||s[r]=='[')
			{
				printf("0");
				return 0;
			}
			if(a[r+1])
			{
				a[r]+=2*a[r+1];
				a[r+1]=0;
			}
			else a[r]+=2;
			--r;
		}
		if(c[i]==']')
		{
			if(!r||s[r]=='(')
			{
				printf("0");
				return 0;
			}
			if(a[r+1])
			{
				a[r]+=3*a[r+1];
				a[r+1]=0;
			}
			else a[r]+=3;
			--r;
		}
	}
	printf("%d",a[1]);
	return 0;
}
